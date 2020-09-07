#include <algorithm>
#include <vector>
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
    first = {0}, second = {0};
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), 0.0));
    first.clear(), second.clear();
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), 0.0));
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    EXPECT_TRUE(cmp(Distance(first, second), 10.247));
    std::copy(first.begin(), first.end(), second.begin());
    EXPECT_TRUE(cmp(Distance(first, second), 0.0));
    first.clear(), second.clear();
    EXPECT_TRUE(cmp(Distance(first, second), 0.0));
}
