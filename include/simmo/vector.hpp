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

    auto& operator *=(const T &scalar)
    {
        std::transform(data.begin(), data.end(), data.begin(), [&scalar](const auto &val)
        {
            return val * scalar;
        });
        return *this;
    }

    auto& operator /=(const T &scalar)
    {
        std::transform(data.begin(), data.end(), data.begin(), [&scalar](const auto &val)
        {
            return val / scalar;
        });
        return *this;
    }
};

typedef vector<double, 0> vector0d;
typedef vector<double, 1> vector1d;
typedef vector<double, 2> vector2d;
typedef vector<double, 3> vector3d;

}

#endif //SIMMOPP_VECTOR_HPP
