#ifndef SIMMOPP_RAY_HPP
#define SIMMOPP_RAY_HPP

#include "basic_line.hpp"

namespace simmo
{

template<typename T, size_t N, typename Base = basic_line<T, N>>
class ray : public Base
{
public:
    using Base::Base;
};

}

#endif //SIMMOPP_RAY_HPP
