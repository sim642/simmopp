#include <gtest/gtest.h>

#include <simmo/angle.hpp>

using namespace simmo;

TEST(angle_test, constructor)
{
    angle a = angle::rad(12.5);
    EXPECT_DOUBLE_EQ(a.rad(), 12.5);

    angle b = angle::deg(12.5);
    EXPECT_DOUBLE_EQ(b.deg(), 12.5);

    angle c = angle::turns(12.5);
    EXPECT_DOUBLE_EQ(c.turns(), 12.5);
}

TEST(angle_test, conversion)
{
    angle a = angle::deg(45);
    EXPECT_DOUBLE_EQ(a.rad(), M_PI / 4);

    angle b = angle::rad(1);
    EXPECT_DOUBLE_EQ(b.deg(), 57.29577951308232087679815481410517033240547246656432154916); // high precision value from WolframAlpha

    angle c = angle::turns(1);
    EXPECT_DOUBLE_EQ(c.deg(), 360.0);
}

TEST(angle_test, plus_minus)
{
    angle a = angle::deg(90);
    angle b = angle::deg(30);

    EXPECT_DOUBLE_EQ((a + b).deg(), 120);
    EXPECT_DOUBLE_EQ((b + a).deg(), 120);

    EXPECT_DOUBLE_EQ((a - b).deg(), 60);
    EXPECT_DOUBLE_EQ((b - a).deg(), -60);
}

TEST(angle_test, assign_plus_minus)
{
    angle a = angle::deg(90);
    EXPECT_DOUBLE_EQ(a.deg(), 90);

    a += angle::deg(10);
    EXPECT_DOUBLE_EQ(a.deg(), 100);

    a -= angle::deg(55);
    EXPECT_DOUBLE_EQ(a.deg(), 45);
}

TEST(angle_test, multiply_divide)
{
    angle a = angle::deg(90);

    EXPECT_DOUBLE_EQ((2 * a).deg(), 180);
    EXPECT_DOUBLE_EQ((a * 2).deg(), 180);
    EXPECT_DOUBLE_EQ((a / 0.5).deg(), 180);

    EXPECT_DOUBLE_EQ((0.5 * a).deg(), 45);
    EXPECT_DOUBLE_EQ((a * 0.5).deg(), 45);
    EXPECT_DOUBLE_EQ((a / 2).deg(), 45);
}

TEST(angle_test, assign_multiply_divide)
{
    angle a = angle::deg(90);
    EXPECT_DOUBLE_EQ(a.deg(), 90);

    a *= 2;
    EXPECT_DOUBLE_EQ(a.deg(), 180);

    a /= 4;
    EXPECT_DOUBLE_EQ(a.deg(), 45);
}

TEST(angle_test, literals)
{
    using namespace angle_literals;

    EXPECT_DOUBLE_EQ((12.5_rad).rad(), 12.5);
    EXPECT_DOUBLE_EQ((-12.5_rad).rad(), -12.5);
    EXPECT_DOUBLE_EQ((5_rad).rad(), 5);
    EXPECT_DOUBLE_EQ((-5_rad).rad(), -5);
    
    EXPECT_DOUBLE_EQ((12.5_deg).deg(), 12.5);
    EXPECT_DOUBLE_EQ((-12.5_deg).deg(), -12.5);
    EXPECT_DOUBLE_EQ((5_deg).deg(), 5);
    EXPECT_DOUBLE_EQ((-5_deg).deg(), -5);
}

TEST(angle_test, normalize_positive)
{
    EXPECT_DOUBLE_EQ(normalize_positive(angle::deg(-360)).deg(), 0);
    EXPECT_DOUBLE_EQ(normalize_positive(angle::deg(-270)).deg(), 90);
    EXPECT_DOUBLE_EQ(normalize_positive(angle::deg(-180)).deg(), 180);
    EXPECT_DOUBLE_EQ(normalize_positive(angle::deg(-90)).deg(), 270);
    EXPECT_DOUBLE_EQ(normalize_positive(angle::deg(0)).deg(), 0);
    EXPECT_DOUBLE_EQ(normalize_positive(angle::deg(90)).deg(), 90);
    EXPECT_DOUBLE_EQ(normalize_positive(angle::deg(180)).deg(), 180);
    EXPECT_DOUBLE_EQ(normalize_positive(angle::deg(270)).deg(), 270);
    EXPECT_DOUBLE_EQ(normalize_positive(angle::deg(360)).deg(), 0);
}

TEST(angle_test, normalize_symmetric)
{
    EXPECT_DOUBLE_EQ(normalize_symmetric(angle::deg(-360)).deg(), 0);
    EXPECT_DOUBLE_EQ(normalize_symmetric(angle::deg(-270)).deg(), 90);
    EXPECT_DOUBLE_EQ(normalize_symmetric(angle::deg(-180)).deg(), -180);
    EXPECT_DOUBLE_EQ(normalize_symmetric(angle::deg(-90)).deg(), -90);
    EXPECT_DOUBLE_EQ(normalize_symmetric(angle::deg(0)).deg(), 0);
    EXPECT_DOUBLE_EQ(normalize_symmetric(angle::deg(90)).deg(), 90);
    EXPECT_DOUBLE_EQ(normalize_symmetric(angle::deg(180)).deg(), -180);
    EXPECT_DOUBLE_EQ(normalize_symmetric(angle::deg(270)).deg(), -90);
    EXPECT_DOUBLE_EQ(normalize_symmetric(angle::deg(360)).deg(), 0);
}

TEST(angle_test, trig)
{
    EXPECT_DOUBLE_EQ(sin(angle::deg(30)), 0.5);
    EXPECT_DOUBLE_EQ(cos(angle::deg(60)), 0.5);
    EXPECT_DOUBLE_EQ(tan(angle::deg(45)), 1.0);
}

TEST(angle_test, arc_trig)
{
    using simmo::asin;
    using simmo::acos;
    using simmo::atan;
    using simmo::atan2;

    EXPECT_DOUBLE_EQ(asin(0.5).deg(), 30);
    EXPECT_DOUBLE_EQ(acos(0.5).deg(), 60);
    EXPECT_DOUBLE_EQ(atan(1.0).deg(), 45);
    EXPECT_DOUBLE_EQ(atan2(2, 2).deg(), 45);
}
