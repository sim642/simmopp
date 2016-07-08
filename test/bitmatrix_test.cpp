#include <gtest/gtest.h>

#include <simmo/bitmatrix.hpp>

using namespace simmo;

TEST(bitmatrix_test, sizeof)
{
    static_assert(sizeof(bitmatrix<2, 2>) == 1, "2x2 size");
    static_assert(sizeof(bitmatrix<2, 4>) == 1, "2x4 size");
    static_assert(sizeof(bitmatrix<1, 8>) == 1, "1x8 size");

    static_assert(sizeof(bitmatrix<3, 3>) == 2, "3x3 size");
    static_assert(sizeof(bitmatrix<3, 4>) == 2, "3x4 size");
    static_assert(sizeof(bitmatrix<4, 4>) == 2, "4x4 size");
    static_assert(sizeof(bitmatrix<1, 16>) == 2, "1x16 size");

    static_assert(sizeof(bitmatrix<5, 5>) == 4, "5x5 size");
    static_assert(sizeof(bitmatrix<3, 6>) == 4, "3x6 size");
    static_assert(sizeof(bitmatrix<4, 8>) == 4, "4x8 size");
    static_assert(sizeof(bitmatrix<1, 32>) == 4, "1x32 size");

    static_assert(sizeof(bitmatrix<6, 6>) == 8, "6x6 size");
    static_assert(sizeof(bitmatrix<4, 9>) == 8, "4x9 size");
    static_assert(sizeof(bitmatrix<8, 8>) == 8, "8x8 size");
    static_assert(sizeof(bitmatrix<1, 64>) == 8, "1x64 size");
}

TEST(bitmatrix_test, constructror)
{
    bitmatrix<2, 3> A;
    EXPECT_EQ(A(0, 0), 0); EXPECT_EQ(A(0, 1), 0); EXPECT_EQ(A(0, 2), 0);
    EXPECT_EQ(A(1, 0), 0); EXPECT_EQ(A(1, 1), 0); EXPECT_EQ(A(1, 2), 0);
    
    bitmatrix<2, 3> B(0b110010);
    EXPECT_EQ(B(0, 0), 0); EXPECT_EQ(B(0, 1), 1); EXPECT_EQ(B(0, 2), 0);
    EXPECT_EQ(B(1, 0), 0); EXPECT_EQ(B(1, 1), 1); EXPECT_EQ(B(1, 2), 1);
    
    bitmatrix<2, 3> C = {{0, 1, 0}, {0, 1, 1}};
    EXPECT_EQ(C(0, 0), 0); EXPECT_EQ(C(0, 1), 1); EXPECT_EQ(C(0, 2), 0);
    EXPECT_EQ(C(1, 0), 0); EXPECT_EQ(C(1, 1), 1); EXPECT_EQ(C(1, 2), 1);
}

TEST(bitmatrix_test, eye)
{
    bitmatrix<2, 3> I = bitmatrix<2, 3>::eye();
    EXPECT_EQ(I(0, 0), 1); EXPECT_EQ(I(0, 1), 0); EXPECT_EQ(I(0, 2), 0);
    EXPECT_EQ(I(1, 0), 0); EXPECT_EQ(I(1, 1), 1); EXPECT_EQ(I(1, 2), 0);
}