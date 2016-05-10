#ifndef SIMMOPP_BASIC_VECTOR_COMPARISON_HPP
#define SIMMOPP_BASIC_VECTOR_COMPARISON_HPP

#include "../basic_vector.hpp"

namespace simmo
{

template<typename T, size_t N>
bool operator <(const basic_vector<T, N> &lhs, const basic_vector<T, N> &rhs)
{
    return lhs.data < rhs.data;
};

}

#endif //SIMMOPP_BASIC_VECTOR_COMPARISON_HPP
