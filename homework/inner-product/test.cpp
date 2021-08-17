#include <vector>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

bool cmp(double first, double second, double epsilon = 0.5) {
    std::cout << "CMP: " << fabs(first - second) << '\n';
    return (fabs(first - second) < epsilon);
}

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    EXPECT_DOUBLE_EQ(ArithmeticAverage(first, second), 2.875);
    // Write more test case
    first = {1, 2, 3, 4};
    second = {1, 2, 3, 4};
    ASSERT_EQ(ArithmeticAverage(first, second), 2.5);
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    double expected = 10.247;
    EXPECT_DOUBLE_EQ(Distance(first, second), expected);

    first = {7, 4, 3, 13};
    second = {17, 6, 2, -2};
    expected = 18.16590212458495;
    EXPECT_TRUE(cmp(Distance(first, second), expected));
    // Write more test case
}
