#include <gtest/gtest.h>

#include <simmo/angle.hpp>

using namespace simmo;

TEST(angle_test, constructor)
{
    angle a = angle::rad(12.5);
    EXPECT_FLOAT_EQ(a.rad(), 12.5);

    angle b = angle::deg(12.5);
    EXPECT_FLOAT_EQ(b.deg(), 12.5);
}


TEST(angle_test, conversion)
{
    angle a = angle::deg(45);
    EXPECT_FLOAT_EQ(a.rad(), M_PI / 4);

    angle b = angle::rad(1);
    EXPECT_FLOAT_EQ(b.deg(), 57.29578);
}
