#include <gtest/gtest.h>

#include <vector>
#include "math.h"

#include "arithmeticAverage.hpp"

bool cmp(double first, double second, double epsilon = 0.5) {
    return (fabs(first - second) < epsilon);
}

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{1, 2, 3, 4};
    std::vector<int> second{1, 2, 3, 4};
    ASSERT_EQ(ArithmeticAverage(first, second), 2.5);
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), 2.875));

    first = {-5, 4, 2, -5, 2, 4, 6, 7};
    second = {3, 5, -2, 6, 7, -3, 6, 9};
    ASSERT_EQ(ArithmeticAverage(first, second), 2.875);
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), 2.875));
    // Write more test case
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    EXPECT_TRUE(cmp(Distance(first, second), 10.247));
    // Write more test case
}
