//
// Created by simmo on 28.02.16.
//

#ifndef SIMMOPP_UTILITY_HPP
#define SIMMOPP_UTILITY_HPP

namespace simmo
{

#define SIMMO_PARAMETER_PACK_APPLY(expr) \
    { \
        int dummy[] = {((expr), 0)...}; \
    } \

}

#endif //SIMMOPP_UTILITY_HPP
