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

    const value_type& rad() const
    {
        return rad_value;
    }

    const value_type& deg() const
    {
        return rad_value / M_PI * 180;
    }

private:
    value_type rad_value;
};

}

#endif //SIMMOPP_ANGLE_HPP
