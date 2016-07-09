#ifndef SIMMOPP_POINT_HPP
#define SIMMOPP_POINT_HPP

#include "basic_vector.hpp"
#include "vector.hpp"
#include <algorithm>

namespace simmo
{

template<typename T, size_t N, typename Base = basic_vector<T, N>>
class point : public Base
{
public:
    using Base::Base;
    using Base::data;

    auto& operator +=(const vector<T, N> &vec)
    {
        std::transform(data.begin(), data.end(), vec.data.begin(), data.begin(), [](const auto &lhs, const auto &rhs)
        {
            return lhs + rhs;
        });
        return *this;
    }

    auto& operator -=(const vector<T, N> &vec)
    {
        std::transform(data.begin(), data.end(), vec.data.begin(), data.begin(), [](const auto &lhs, const auto &rhs)
        {
            return lhs - rhs;
        });
        return *this;
    }
};

template<typename T, size_t N>
bool operator ==(const point<T, N> &lhs, const point<T, N> &rhs)
{
    return lhs.data == rhs.data;
};

template<typename T, size_t N>
bool operator !=(const point<T, N> &lhs, const point<T, N> &rhs)
{
    return lhs.data != rhs.data;
};

template<typename T, size_t N>
point<T, N> operator +(const point<T, N> &lhs, const vector<T, N> &rhs)
{
    point<T, N> ret = lhs;
    return ret += rhs;
};

template<typename T, size_t N>
point<T, N> operator +(const vector<T, N> &lhs, const point<T, N> &rhs)
{
    point<T, N> ret = rhs;
    return ret += lhs;
};

template<typename T, size_t N>
point<T, N> operator -(const point<T, N> &lhs, const vector<T, N> &rhs)
{
    point<T, N> ret = lhs;
    return ret -= rhs;
};

template<typename T, size_t N>
vector<T, N> operator -(const point<T, N> &lhs, const point<T, N> &rhs)
{
    vector<T, N> ret;
    std::transform(lhs.data.begin(), lhs.data.end(), rhs.data.begin(), ret.data.begin(), [](const auto &lhs, const auto &rhs)
    {
        return lhs - rhs;
    });
    return ret;
};

typedef point<int, 1> point1i;
typedef point<int, 2> point2i;
typedef point<int, 3> point3i;
typedef point<float, 1> point1f;
typedef point<float, 2> point2f;
typedef point<float, 3> point3f;
typedef point<double, 1> point1d;
typedef point<double, 2> point2d;
typedef point<double, 3> point3d;

}

namespace std
{

template<typename T, size_t N>
struct hash<simmo::point<T, N>>
{
    size_t operator()(const simmo::point<T, N> &vector) const
    {
        return hash<simmo::basic_vector<T, N>>()(vector);
    }
};

}

#endif //SIMMOPP_POINT_HPP
