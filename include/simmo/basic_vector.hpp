//
// Created by simmo on 2.03.16.
//

#ifndef SIMMOPP_BASIC_VECTOR_HPP
#define SIMMOPP_BASIC_VECTOR_HPP

#include <array>
#include <type_traits>
#include <utility>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <ostream>
#include <functional>

namespace simmo
{

template<typename T, size_t N>
class basic_vector
{
public:
    basic_vector() = default;

    basic_vector(const basic_vector<T, N> &other) : data(other.data)
    {

    }

    basic_vector(basic_vector<T, N> &&other) : data(std::move(other.data))
    {

    }

    template<typename U>
    basic_vector(const basic_vector<U, N> &other)
    {
        std::copy(other.data.begin(), other.data.end(), data.begin());
    }

    // TODO: cross-type move constructor

    template<typename... Ts>
    explicit basic_vector(const T &val, const Ts&... vals) : data{{val, static_cast<T>(vals)...}}
    {

    }

    basic_vector(std::initializer_list<T> vals)
    {
        if (vals.size() > N)
            throw std::out_of_range("basic_vector: initializer list too large");

        std::copy(vals.begin(), vals.end(), data.begin());
        std::uninitialized_fill(data.begin() + vals.size(), data.end(), T());
    }

    auto& operator =(const basic_vector<T, N> &other)
    {
        data = other.data;
        return *this;
    }

    auto& operator =(basic_vector<T, N> &&other)
    {
        data = std::move(other.data);
        return *this;
    }

    auto& operator =(std::initializer_list<T> vals)
    {
        if (vals.size() > N)
            throw std::out_of_range("basic_vector: initializer list too large");

        std::copy(vals.begin(), vals.end(), data.begin());
        std::uninitialized_fill(data.begin() + vals.size(), data.end(), T());
        return *this;
    }

    // TODO: cross-type assignment operator
    // TODO: cross-type move assignment operator

public:

#define BASIC_VECTOR_COORDINATE(name, i) \
    auto& name() \
    { \
        return std::enable_if_t<(N > i), T&>(data[i]); \
    } \
     \
    const auto& name() const \
    { \
        return std::enable_if_t<(N > i), const T&>(data[i]); \
    }

    BASIC_VECTOR_COORDINATE(x, 0);
    BASIC_VECTOR_COORDINATE(y, 1);
    BASIC_VECTOR_COORDINATE(z, 2);

#undef BASIC_VECTOR_COORDINATE

public:
    std::array<T, N> data;
};

template<typename T, size_t N>
std::ostream& operator <<(std::ostream &out, const basic_vector<T, N> &vector)
{
    out << "(";
    for (auto it = vector.data.begin(); it != vector.data.end(); ++it)
    {
        if (it != vector.data.begin())
            out << ", ";
        out << *it;
    }
    out << ")";
    return out;
};

}

namespace std
{

template<>
template<typename T, size_t N>
struct hash<simmo::basic_vector<T, N>>
{
    size_t operator ()(const simmo::basic_vector<T, N> &vector) const
    {
        size_t h = 0;
        for (const T &val : vector.data) {
            h ^= std::hash<T>()(val);
        }
        return h;
    }
};

}

#endif //SIMMOPP_BASIC_VECTOR_HPP
