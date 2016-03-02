//
// Created by simmo on 2.03.16.
//

#ifndef SIMMOPP_BASIC_VECTOR_HPP
#define SIMMOPP_BASIC_VECTOR_HPP

#include <array>
#include <type_traits>

namespace simmo
{

template<typename T, size_t N>
class basic_vector
{
public:

#define BASIC_VECTOR_COORDINATE(name, i) \
    auto& name() \
    { \
        return std::enable_if_t<(N > i), T&>(data[i]); \
    }

    BASIC_VECTOR_COORDINATE(x, 0);
    BASIC_VECTOR_COORDINATE(y, 1);
    BASIC_VECTOR_COORDINATE(z, 2);

#undef BASIC_VECTOR_COORDINATE

public: // TODO: make private, create contructors
    std::array<T, N> data;
};

}

#endif //SIMMOPP_BASIC_VECTOR_HPP
