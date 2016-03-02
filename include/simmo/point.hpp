//
// Created by simmo on 2.03.16.
//

#ifndef SIMMOPP_POINT_HPP
#define SIMMOPP_POINT_HPP

#include "basic_vector.hpp"

namespace simmo
{

template<typename T, size_t N>
class point : public basic_vector<T, N>
{
public:
    using basic_vector<T, N>::basic_vector;
};

typedef point<double, 0> point0d;
typedef point<double, 1> point1d;
typedef point<double, 2> point2d;
typedef point<double, 3> point3d;

}

#endif //SIMMOPP_POINT_HPP
