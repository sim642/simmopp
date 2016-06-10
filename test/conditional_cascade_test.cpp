#include <gtest/gtest.h>

#include <simmo/metaprogramming/conditional_cascade.hpp>
#include <type_traits>

using namespace simmo;
using namespace std;

template<uint8_t N>
using uint_t = typename conditional_cascade<
    enable_if<N <= 8, uint8_t>,
    enable_if<N <= 16, uint16_t>,
    enable_if<N <= 32, uint32_t>,
    enable_if<N <= 64, uint64_t>,
    type_wrapper<void>
>::type;

TEST(conditional_cascade_test, test)
{
    ::testing::StaticAssertTypeEq<uint_t<4>, uint8_t>();
    ::testing::StaticAssertTypeEq<uint_t<8>, uint8_t>();

    ::testing::StaticAssertTypeEq<uint_t<12>, uint16_t>();
    ::testing::StaticAssertTypeEq<uint_t<16>, uint16_t>();

    ::testing::StaticAssertTypeEq<uint_t<24>, uint32_t>();
    ::testing::StaticAssertTypeEq<uint_t<32>, uint32_t>();

    ::testing::StaticAssertTypeEq<uint_t<48>, uint64_t>();
    ::testing::StaticAssertTypeEq<uint_t<64>, uint64_t>();

    ::testing::StaticAssertTypeEq<uint_t<96>, void>();
}