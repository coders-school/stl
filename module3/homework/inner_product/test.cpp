#include <vector>

#include <algorithm>
#include <cmath>
#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

bool cmp(double first, double second, double epsilon = 0.5) {
    return (fabs(first - second) < epsilon);
}

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), 2.875));
    first.clear();
    second.clear();
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), 0.0));
    first = {2};
    second = {2};
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), 2.0));
    first = {std::numeric_limits<int>::min()};
    second = {std::numeric_limits<int>::max()};
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), -0.5));
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    EXPECT_TRUE(cmp(Distance(first, second), 10.247));
    first.clear();
    second.clear();
    EXPECT_TRUE(cmp(Distance(first, second), 0.0));
    first = {1, 2, 3};
    second = {5, 6};
    EXPECT_TRUE(cmp(Distance(first, second), 0.0));
}
