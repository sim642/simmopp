//
// Created by simmo on 28.02.16.
//

#ifndef SIMMOPP_BASIC_VECTOR_HPP
#define SIMMOPP_BASIC_VECTOR_HPP

#include <array>
#include <type_traits>

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
        auto copy = array;

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

    auto x()
    {
        return basic_swizzle<this_t, 0>(*this);
    };

    auto y()
    {
        return basic_swizzle<this_t, 1>(*this);
    };

    auto z()
    {
        return basic_swizzle<this_t, 2>(*this);
    };

    auto xy()
    {
        return basic_swizzle<this_t, 0, 1>(*this);
    }

    auto xz()
    {
        return basic_swizzle<this_t, 0, 2>(*this);
    }

    auto yz()
    {
        return basic_swizzle<this_t, 1, 2>(*this);
    }

    auto yx()
    {
        return basic_swizzle<this_t, 1, 0>(*this);
    }

    auto zx()
    {
        return basic_swizzle<this_t, 2, 0>(*this);
    }

    auto zy()
    {
        return basic_swizzle<this_t, 2, 1>(*this);
    }
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


#endif //SIMMOPP_BASIC_VECTOR_HPP
