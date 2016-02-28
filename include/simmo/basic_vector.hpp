//
// Created by simmo on 28.02.16.
//

#ifndef SIMMOPP_BASIC_VECTOR_HPP
#define SIMMOPP_BASIC_VECTOR_HPP

#include <array>
#include <type_traits>

namespace simmo
{

template<typename V, size_t I, size_t... Is>
class basic_swizzle
{
public:
    typedef typename V::array_t array_t;
    typedef typename V::template resize_t<1 + sizeof...(Is)> vector_t;

    basic_swizzle(V &vector) : array(vector.array)
    {

    }

    /*template<size_t... Is_>
    basic_swizzle(basic_swizzle<V, Is_...> &swizzle) : array(swizzle.array)
    {

    }*/

    operator vector_t ()
    {
        return vector_t{array[I], array[Is]...};
    }

    template<size_t I_, size_t... Is_>
    auto& operator =(const basic_swizzle<V, I_, Is_...> &other)
    {
        auto copy = other.array;

        array[I] = copy[I_];
        int dummy[sizeof...(Is)] = { (array[Is] = copy[Is_], 0)... };

        return *this;
    };

    /*operator std::enable_if_t<sizeof...(Is) == 0, typename array_t::value_type>()
    {
        return array[I];
    }*/

    array_t &array;
};

template<size_t N, size_t I, size_t... Is>
struct indices_pack
{
    static constexpr size_t other_max = indices_pack<N, Is...>::max;
    static constexpr size_t max = I > other_max ? I : other_max;
};

template<size_t N, size_t I>
struct indices_pack<N, I>
{
    static constexpr size_t max = I;
};

template<typename T, size_t N>
class basic_vector
{
public:
    typedef basic_vector<T, N> this_t;
    typedef std::array<T, N> array_t;

    template<size_t N_>
    using resize_t = basic_vector<T, N_>;

    /*basic_vector(std::initializer_list<T> list)
    {
        std::copy(list.begin(), list.end(), array.begin());
    }

    template<size_t N_, size_t... Is>
    basic_vector(basic_swizzle<T, N_, Is...> swizzle)
    {

    };*/

    array_t array;

#define BASIC_VECTOR_SWIZZLE(name, ...) \
    auto name() \
    { \
        return std::enable_if_t<indices_pack<N, __VA_ARGS__>::max < N, basic_swizzle<this_t, __VA_ARGS__>>(*this); \
    }

    BASIC_VECTOR_SWIZZLE(x, 0);
    BASIC_VECTOR_SWIZZLE(y, 1);
    BASIC_VECTOR_SWIZZLE(z, 2);

    BASIC_VECTOR_SWIZZLE(xy, 0, 1);
    BASIC_VECTOR_SWIZZLE(yx, 1, 0);
    BASIC_VECTOR_SWIZZLE(xz, 0, 2);
    BASIC_VECTOR_SWIZZLE(zx, 2, 0);
    BASIC_VECTOR_SWIZZLE(yz, 1, 2);
    BASIC_VECTOR_SWIZZLE(zy, 2, 1);

    BASIC_VECTOR_SWIZZLE(xyz, 0, 1, 2);
    BASIC_VECTOR_SWIZZLE(xzy, 0, 2, 1);
    BASIC_VECTOR_SWIZZLE(yxz, 1, 0, 2);
    BASIC_VECTOR_SWIZZLE(yzx, 1, 2, 0);
    BASIC_VECTOR_SWIZZLE(zxy, 2, 0, 1);
    BASIC_VECTOR_SWIZZLE(zyz, 2, 1, 0);

#undef BASIC_VECTOR_SWIZZLE
};

template<typename T, size_t N>
std::ostream& operator <<(std::ostream &out, const basic_vector<T, N> &vector)
{
    out << "(";
    for (auto it = vector.array.begin(); it != vector.array.end(); ++it)
    {
        if (it != vector.array.begin())
            out << ", ";
        out << *it;
    }
    out << ")";
    return out;
};

}

#endif //SIMMOPP_BASIC_VECTOR_HPP
