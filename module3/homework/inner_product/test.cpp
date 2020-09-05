#include <math.h>

#include <vector>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

bool cmp(double first, double second, double epsilon = 0.5) {
    return (fabs(first - second) < epsilon);
}

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), 2.875));
    EXPECT_TRUE(cmp(ArithmeticAverage({1, 2, 3, 4}, {1, 2, 3, 4}), 2.5));
    EXPECT_TRUE(cmp(ArithmeticAverage({1, 2, 3}, {1, 2, 3}), 2));
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    EXPECT_TRUE(cmp(Distance(first, second), 10.247));
    EXPECT_TRUE(cmp(Distance({14, 1}, {12, 4}), 3.60555));
    EXPECT_TRUE(cmp(Distance({-7, 4, -3}, {17, -6, 2}), 26.476405));
    EXPECT_TRUE(cmp(Distance({0, 0, 0}, {0, 0, 0}), 0));
}
