#include <vector>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

constexpr double epsilon = 0.001;

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage)
{
    std::vector<int> first { -5, 4, 2, -5, 2, 4, 6, 7 };
    std::vector<int> second { 3, 5, -2, 6, 7, -3, 6, 9 };
    EXPECT_NEAR(ArithmeticAverage(first, second), 2.875, epsilon);
    // Write more test case
    first = { 10, 2, 38, 23, 38, 23, 21, 23, 45 };
    second = { 33, -4, 12, 17, 133, -33, 4, 143, 11 };
    EXPECT_NEAR(ArithmeticAverage(first, second), 29.944, epsilon);

    first = { -44, 0, 33, 11, 0, 77, 99, 13, 555, 21 };
    second = { 1223, -73, 88, 12, -3, 43, -99, -4, -920, 1999 };
    EXPECT_NEAR(ArithmeticAverage(first, second), 151.55, epsilon);
}

TEST(arithmeticAverageTest, ShouldCalculateDistance)
{
    std::vector<int> first { 7, 4, 3 };
    std::vector<int> second { 17, 6, 2 };
    double expected = 10.247;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);

    first = { 7, 4, 3, 13 };
    second = { 17, 6, 2, -2 };
    expected = 18.16590212458495;
    EXPECT_NEAR(Distance(first, second), expected, 0.00001);
    // Write more test case
    first = { 3, 8 };
    second = { -20, 11 };
    expected = 23.195;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);

    first = { 9 };
    second = { -4 };
    expected = 13;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);
}
