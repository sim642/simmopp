#include <gtest/gtest.h>

TEST(T1, good)
{
    EXPECT_EQ(1, 1);
    EXPECT_NE(1, 2);
}

TEST(T1, bad)
{
    EXPECT_EQ(1, 2);
    EXPECT_NE(1, 1);
}