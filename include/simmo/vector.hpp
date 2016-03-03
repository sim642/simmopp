//
// Created by simmo on 2.03.16.
//

#ifndef SIMMOPP_VECTOR_HPP
#define SIMMOPP_VECTOR_HPP

#include "basic_vector.hpp"
#include <algorithm>

namespace simmo
{

template<typename T, size_t N, typename Base = basic_vector<T, N>>
class vector : public Base
{
public:
    using Base::Base;
    using Base::data;

    auto& operator +()
    {
        return *this;
    }

    auto& operator -()
    {
        std::transform(data.begin(), data.end(), data.begin(), [](const auto &val)
        {
            return -val;
        });
        return *this;
    }

    auto& operator +=(const vector<T, N> &other)
    {
        std::transform(data.begin(), data.end(), other.data.begin(), data.begin(), [](const auto &lhs, const auto &rhs)
        {
            return lhs + rhs;
        });
        return *this;
    }

    auto& operator -=(const vector<T, N> &other)
    {
        std::transform(data.begin(), data.end(), other.data.begin(), data.begin(), [](const auto &lhs, const auto &rhs)
        {
            return lhs - rhs;
        });
        return *this;
    }

    auto& operator *=(const T &scalar) // TODO: is_convertible
    {
        std::transform(data.begin(), data.end(), data.begin(), [&scalar](const auto &val)
        {
            return val * scalar;
        });
        return *this;
    }

    auto& operator /=(const T &scalar) // TODO: is_convertible
    {
        std::transform(data.begin(), data.end(), data.begin(), [&scalar](const auto &val)
        {
            return val / scalar;
        });
        return *this;
    }
};

template<typename T, size_t N>
vector<T, N> operator +(const vector<T, N> &lhs, const vector<T, N> &rhs)
{
    vector<T, N> ret = lhs;
    return ret += rhs;
};

template<typename T, size_t N>
vector<T, N> operator -(const vector<T, N> &lhs, const vector<T, N> &rhs)
{
    vector<T, N> ret = lhs;
    return ret -= rhs;
};

template<typename T, size_t N>
vector<T, N> operator *(const vector<T, N> &lhs, const T &rhs)
{
    vector<T, N> ret = lhs;
    return ret *= rhs;
};

template<typename T, size_t N>
vector<T, N> operator *(const T &lhs, const vector<T, N> &rhs)
{
    vector<T, N> ret = rhs;
    return ret *= lhs;
};

template<typename T, size_t N>
vector<T, N> operator /(const vector<T, N> &lhs, const T &rhs)
{
    vector<T, N> ret = lhs;
    return ret /= rhs;
};

template<typename T, size_t N>
T dot(const vector<T, N> &lhs, const vector<T, N> &rhs)
{
    return std::inner_product(lhs.data.begin(), lhs.data.end(), rhs.data.begin(), T(0));
};

template<typename T>
vector<T, 3> cross(const vector<T, 3> &lhs, const vector<T, 3> &rhs)
{
    return
    {
        lhs.y() * rhs.z() - lhs.z() * rhs.y(),
        -(lhs.x() * rhs.z() - lhs.z() * rhs.x()),
        lhs.x() * rhs.y() - lhs.y() * rhs.x()
    };
};

template<typename T, size_t N>
auto norm(const vector<T, N> &vec)
{
    return std::sqrt(dot(vec, vec));
};

typedef vector<int, 1> vector1i;
typedef vector<int, 2> vector2i;
typedef vector<int, 3> vector3i;
typedef vector<float, 1> vector1f;
typedef vector<float, 2> vector2f;
typedef vector<float, 3> vector3f;
typedef vector<double, 1> vector1d;
typedef vector<double, 2> vector2d;
typedef vector<double, 3> vector3d;

}

#endif //SIMMOPP_VECTOR_HPP
