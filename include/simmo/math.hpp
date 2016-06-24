#ifndef SIMMOPP_MATH_HPP
#define SIMMOPP_MATH_HPP

#include <cmath>

namespace simmo
{

// http://stackoverflow.com/a/29871193/854540
template<typename T>
T wrap_max(T x, T max)
{
    return std::fmod(max + std::fmod(x, max), max);
}

// http://stackoverflow.com/a/29871193/854540
template<typename T>
T wrap_min_max(T x, T min, T max)
{
    return min + wrap_max(x - min, max - min);
}

}

#endif //SIMMOPP_MATH_HPP
