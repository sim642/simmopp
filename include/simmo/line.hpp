#ifndef SIMMOPP_LINE_HPP
#define SIMMOPP_LINE_HPP

#include "basic_line.hpp"

namespace simmo
{

template<typename T, size_t N, typename Base = basic_line<T, N>>
class line : public Base
{
public:
    using Base::Base;
};

}

#endif //SIMMOPP_LINE_HPP
