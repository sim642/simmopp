//
// Created by simmo on 2.03.16.
//

#ifndef SIMMOPP_POINT_HPP
#define SIMMOPP_POINT_HPP

#include "basic_vector.hpp"

namespace simmo
{

template<typename T, size_t N, typename Base = basic_vector<T, N>>
class point : public Base
{
public:
    using Base::Base;
    using Base::data;
};

typedef point<double, 0> point0d;
typedef point<double, 1> point1d;
typedef point<double, 2> point2d;
typedef point<double, 3> point3d;

}

#endif //SIMMOPP_POINT_HPP
