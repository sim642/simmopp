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

TEST(vector_test, unary_plus_minus)
{
    vector2i v(1, -2);
    EXPECT_EQ(+v, v);

    vector2i mv(-1, 2);
    EXPECT_EQ(-v, mv);
}


TEST(vector_test, binary_plus_minus)
{
    vector2i u(1, -2);
    vector2i v(-3, 7);

    vector2i sum(-2, 5);
    EXPECT_EQ(u + v, sum);
    EXPECT_EQ(v + u, sum);

    vector2i diff1(4, -9);
    EXPECT_EQ(u - v, diff1);

    vector2i diff2(-4, 9);
    EXPECT_EQ(v - u, diff2);
}

TEST(vector_test, binary_mult_div)
{
    vector2i v(3, -20);

    vector2i triple(9, -60);
    EXPECT_EQ(3 * v, triple);
    EXPECT_EQ(v * 3, triple);

    vector2i half(1, -10);
    EXPECT_EQ(v / 2, half);
}

TEST(vector_test, assign_plus_minus)
{
    vector2i a(1, 2), b(5, 6), c(-2, 5);

    vector2i sum(6, 8);
    ASSERT_EQ(a += b, sum);

    vector2i diff(8, 3);
    ASSERT_EQ(a -= c, diff);
}

TEST(vector_test, assign_mult_div)
{
    vector2i v(3, -20);

    vector2i triple(9, -60);
    ASSERT_EQ(v *= 3, triple);

    vector2i half(4, -30);
    ASSERT_EQ(v /= 2, half);
}
