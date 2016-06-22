#ifndef SIMMOPP_ANGLE_HPP
#define SIMMOPP_ANGLE_HPP

#include <cmath>

namespace simmo
{

class angle
{
public:
    typedef double value_type;

private:
    angle(value_type rad_value) : rad_value(rad_value)
    {

    }

public:
    static angle rad(value_type rad_value)
    {
        return angle(rad_value);
    }

    static angle deg(value_type deg_value)
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

}

#endif //SIMMOPP_ANGLE_HPP
