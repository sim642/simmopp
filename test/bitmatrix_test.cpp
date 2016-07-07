#include <gtest/gtest.h>

#include <simmo/bitmatrix.hpp>

using namespace simmo;

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