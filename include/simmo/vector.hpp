//
// Created by simmo on 2.03.16.
//

#ifndef SIMMOPP_VECTOR_HPP
#define SIMMOPP_VECTOR_HPP

#include "basic_vector.hpp"

namespace simmo
{

template<typename T, size_t N>
class vector : public basic_vector<T, N>
{
public:
    using basic_vector<T, N>::basic_vector;
};

typedef vector<double, 0> vector0d;
typedef vector<double, 1> vector1d;
typedef vector<double, 2> vector2d;
typedef vector<double, 3> vector3d;

}

#endif //SIMMOPP_VECTOR_HPP
