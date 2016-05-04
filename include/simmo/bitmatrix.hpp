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

    friend bool operator ==(const bitmatrix &lhs, const bitmatrix &rhs)
    {
        return lhs.bits == rhs.bits;
    }

private:
    static const bits_t mask = (1 << (M * N)) - 1;

    bits_t bits;
};

}

#endif //SIMMOPP_BITMATRIX_HPP
