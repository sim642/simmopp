#ifndef SIMMOPP_BITMATRIX_HPP
#define SIMMOPP_BITMATRIX_HPP

#include <cstdint>
#include <type_traits>
#include <utility>

namespace simmo
{

template<uint8_t N>
using uint_t = std::conditional_t<N <= 8,
    uint8_t,
    std::conditional_t<N <= 16,
        uint16_t,
        std::conditional_t<N <= 32,
            uint32_t,
            std::enable_if_t<N <= 64,
                uint64_t
            >
        >
    >
>;

typedef uint8_t dimsize_t;

template<dimsize_t M, dimsize_t N>
class bitmatrix
{
public:
    typedef uint_t<M * N> bits_t;

    static bitmatrix eye()
    {
        bitmatrix bm;
        for (int i = 0; i < std::min(M, N); ++i)
            bm.set(i, i);
        return bm;
    }

    bitmatrix() : bits{0}
    {

    }

    bitmatrix(const bitmatrix &other) : bits{other.bits}
    {

    }

    bitmatrix(bitmatrix &&other) : bits{std::move(other.bits)}
    {

    }

    explicit bitmatrix(bits_t bits) : bits(bits & mask)
    {

    }

    bitmatrix& operator =(const bitmatrix &other)
    {
        bits = other.bits;
        return *this;
    }

    bitmatrix& operator =(bitmatrix &&other)
    {
        bits = std::move(other.bits);
        return *this;
    }

    explicit operator bits_t() const
    {
        return bits;
    }

    bool get(dimsize_t row, dimsize_t col) const
    {
        return (bits >> (N * row + col)) & 0x1;
    }

    bitmatrix& set(dimsize_t row, dimsize_t col)
    {
        bits |= (0x1 << (N * row + col));
        return *this;
    }

    bitmatrix& clear(dimsize_t row, dimsize_t col)
    {
        bits &= ~(0x1 << (N * row + col));
        return *this;
    }

    bitmatrix& write(dimsize_t row, dimsize_t col, bool value)
    {
        return value ? set(row, col) : clear(row, col);
    }

private:
    class reference
    {
    public:
        reference(bitmatrix &bm, dimsize_t row, dimsize_t col) : bm(bm), row(row), col(col)
        {

        }

        operator bool() const
        {
            return bm.get(row, col);
        }

        reference& operator =(bool value)
        {
            bm.write(row, col, value);
            return *this;
        }

        reference& operator =(const reference &other)
        {
            *this = static_cast<bool>(other);
            return *this;
        }

        void swap(reference other)
        {
            bool tmp = static_cast<bool>(*this);
            *this = other;
            other = tmp;
        }

    private:
        bitmatrix &bm;
        dimsize_t row, col;
    };

public:
    reference operator ()(dimsize_t row, dimsize_t col)
    {
        return reference(*this, row, col);
    }

    bool operator ()(dimsize_t row, dimsize_t col) const
    {
        return get(row, col);
    }

    bitmatrix operator ~() const
    {
        return bitmatrix(~bits);
    }

    bitmatrix& operator &=(const bitmatrix &other)
    {
        bits &= other.bits;
        return *this;
    }

    bitmatrix& operator |=(const bitmatrix &other)
    {
        bits |= other.bits;
        return *this;
    }

    bitmatrix& operator ^=(const bitmatrix &other)
    {
        bits ^= other.bits;
        return *this;
    }

    bitmatrix& operator +=(const bitmatrix &other)
    {
        return *this |= other;
    }

    friend bool operator ==(const bitmatrix &lhs, const bitmatrix &rhs)
    {
        return lhs.bits == rhs.bits;
    }

private:
    static const bits_t mask = (1 << (M * N)) - 1;

    bits_t bits;
};

template<dimsize_t M, dimsize_t N>
bitmatrix<M, N> operator &(const bitmatrix<M, N> &lhs, const bitmatrix<M, N> &rhs)
{
    bitmatrix<M, N> bm = lhs;
    return bm &= rhs;
};

template<dimsize_t M, dimsize_t N>
bitmatrix<M, N> operator |(const bitmatrix<M, N> &lhs, const bitmatrix<M, N> &rhs)
{
    bitmatrix<M, N> bm = lhs;
    return bm |= rhs;
};

template<dimsize_t M, dimsize_t N>
bitmatrix<M, N> operator ^(const bitmatrix<M, N> &lhs, const bitmatrix<M, N> &rhs)
{
    bitmatrix<M, N> bm = lhs;
    return bm ^= rhs;
};

template<dimsize_t M, dimsize_t N>
bitmatrix<M, N> operator +(const bitmatrix<M, N> &lhs, const bitmatrix<M, N> &rhs)
{
    bitmatrix<M, N> bm = lhs;
    return bm += rhs;
};

template<dimsize_t M, dimsize_t N, dimsize_t P>
bitmatrix<M, P> operator *(const bitmatrix<M, N> &lhs, const bitmatrix<N, P> &rhs)
{
    bitmatrix<M, P> bm;
    for (int row = 0; row < M; row++)
    {
        for (int col = 0; col < P; col++)
        {
            bool value = false;

            for (int k = 0; !value && k < N; k++)
                value |= lhs(row, k) && rhs(k, col);

            bm(row, col) = value;
        }
    }
    return bm;
};

}

#endif //SIMMOPP_BITMATRIX_HPP
