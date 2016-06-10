#include <gtest/gtest.h>

#include <simmo/point.hpp>
#include <simmo/basic_vector/comparison.hpp>

using namespace simmo;

TEST(point_test, vector_plus_minus)
{
    point2i A(5, 7);
    vector2i v(1, 2);

    point2i sum(6, 9);
    EXPECT_EQ(A + v, sum);
    EXPECT_EQ(v + A, sum);

    point2i diff(4, 5);
    EXPECT_EQ(A - v, diff);
}

TEST(point_test, point_minus)
{
    point2i A(5, 7), B(1, -3);

    vector2i diff1(4, 10);
    EXPECT_EQ(A - B, diff1);

    vector2i diff2(-4, -10);
    EXPECT_EQ(B - A, diff2);
}

TEST(point_test, vector_assign_plus_minus)
{
    point2i A(5, 7);
    vector2i a(1, 2), b(5, 6);

    point2i sum(6, 9);
    ASSERT_EQ(A += a, sum);

    point2i diff(1, 3);
    ASSERT_EQ(A -= b, diff);
}

TEST(point_test, equals)
{
    point2i A(1, -2), B(1, -2), C(1, 2);

    EXPECT_EQ(A, B);
    EXPECT_EQ(B, A);

    /*EXPECT_NE(A, C);
    EXPECT_NE(B, C);*/
}

TEST(point_test, hash)
{
    point2i A(1, -2), B(1, -2);

    auto hashA = std::hash<point2i>()(A);
    auto hashB = std::hash<point2i>()(B);

    EXPECT_EQ(hashA, hashB);
}

TEST(point_test, comparison)
{
    point2i A(1, 2), B(1, 3), C(2, 3);

    EXPECT_TRUE(A < B);
    EXPECT_TRUE(A < C);
    EXPECT_TRUE(B < C);

    EXPECT_FALSE(B < A);
    EXPECT_FALSE(C < A);
    EXPECT_FALSE(C < B);

    EXPECT_FALSE(A < A);
    EXPECT_FALSE(B < B);
    EXPECT_FALSE(C < C);
}
