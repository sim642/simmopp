#ifndef SIMMOPP_ANGLE_HPP
#define SIMMOPP_ANGLE_HPP

#include "math.hpp"
#include <cmath>

namespace simmo
{

class angle
{
public:
    typedef double value_type;

private:
    constexpr angle(value_type rad_value) : rad_value(rad_value)
    {

    }

public:
    constexpr static angle rad(value_type rad_value)
    {
        return angle(rad_value);
    }

    constexpr static angle deg(value_type deg_value)
    {
        return angle(deg_value / 180 * M_PI);
    }

    value_type rad() const
    {
        return rad_value;
    }

    value_type deg() const
    {
        return rad_value / M_PI * 180;
    }

    auto operator +() const
    {
        return *this;
    }

    auto operator -() const
    {
        return angle(-rad_value);
    }

    auto& operator +=(const angle &other)
    {
        rad_value += other.rad_value;
        return *this;
    }

    auto& operator -=(const angle &other)
    {
        rad_value -= other.rad_value;
        return *this;
    }

    auto& operator *=(value_type factor)
    {
        rad_value *= factor;
        return *this;
    }

    auto& operator /=(value_type factor)
    {
        rad_value /= factor;
        return *this;
    }

private:
    value_type rad_value;
};

angle operator +(const angle &lhs, const angle &rhs)
{
    angle ret = lhs;
    return ret += rhs;
}

angle operator -(const angle &lhs, const angle &rhs)
{
    angle ret = lhs;
    return ret -= rhs;
}

angle operator *(const angle &lhs, angle::value_type rhs)
{
    angle ret = lhs;
    return ret *= rhs;
}

angle operator *(angle::value_type lhs, const angle &rhs)
{
    angle ret = rhs;
    return ret *= lhs;
}

angle operator /(const angle &lhs, angle::value_type rhs)
{
    angle ret = lhs;
    return ret /= rhs;
}

namespace angle_literals
{
    constexpr angle operator"" _rad(long double rad_value)
    {
        return angle::rad(rad_value);
    }

    constexpr angle operator"" _rad(unsigned long long rad_value)
    {
        return angle::rad(rad_value);
    }

    constexpr angle operator"" _deg(long double deg_value)
    {
        return angle::deg(deg_value);
    }

    constexpr angle operator"" _deg(unsigned long long deg_value)
    {
        return angle::deg(deg_value);
    }
}

auto normalize_positive(const angle &a)
{
    return angle::rad(wrap_max(a.rad(), 2 * M_PI));
}

auto normalize_symmetric(const angle &a)
{
    return angle::rad(wrap_min_max(a.rad(), -M_PI, M_PI));
}

auto sin(const angle &a)
{
    return std::sin(a.rad());
}

auto cos(const angle &a)
{
    return std::cos(a.rad());
}

auto tan(const angle &a)
{
    return std::tan(a.rad());
}

angle asin(auto x)
{
    return angle::rad(std::asin(x));
}

angle acos(auto x)
{
    return angle::rad(std::acos(x));
}

angle atan(auto x)
{
    return angle::rad(std::atan(x));
}

angle atan2(auto y, auto x)
{
    return angle::rad(std::atan2(y, x));
}

}

#endif //SIMMOPP_ANGLE_HPP
