#ifndef SIMMOPP_SEGMENT_HPP
#define SIMMOPP_SEGMENT_HPP

#include "basic_line.hpp"

namespace simmo
{

template<typename T, size_t N, typename Base = basic_line<T, N>>
class segment : public Base
{
public:
    using Base::Base;
};

}

#endif //SIMMOPP_SEGMENT_HPP
