#include <gtest/gtest.h>

#include <simmo/vector.hpp>

using namespace simmo;

TEST(vector_test, 1d_access)
{
    vector1i v(1);
    EXPECT_EQ(v.x(), 1);

    v.x() = -2;
    EXPECT_EQ(v.x(), -2);
}

TEST(vector_test, 2d_access)
{
    vector2i v(1, -2);
    EXPECT_EQ(v.x(), 1);
    EXPECT_EQ(v.y(), -2);

    v.x() = -4;
    EXPECT_EQ(v.x(), -4);
    EXPECT_EQ(v.y(), -2);

    v.y() = 6;
    EXPECT_EQ(v.x(), -4);
    EXPECT_EQ(v.y(), 6);
}

TEST(vector_test, 3d_access)
{
    vector3i v(1, -2, 3);
    EXPECT_EQ(v.x(), 1);
    EXPECT_EQ(v.y(), -2);
    EXPECT_EQ(v.z(), 3);

    v.x() = -4;
    EXPECT_EQ(v.x(), -4);
    EXPECT_EQ(v.y(), -2);
    EXPECT_EQ(v.z(), 3);

    v.y() = 6;
    EXPECT_EQ(v.x(), -4);
    EXPECT_EQ(v.y(), 6);
    EXPECT_EQ(v.z(), 3);

    v.z() = -7;
    EXPECT_EQ(v.x(), -4);
    EXPECT_EQ(v.y(), 6);
    EXPECT_EQ(v.z(), -7);
}
