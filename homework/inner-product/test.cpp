#include <vector>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

constexpr double epsilon = 0.001;

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    EXPECT_NEAR(ArithmeticAverage(first, second), 2.875, epsilon);
    // Write more test case
    first = {1, 2, 3, 4};
    second = {1, 2, 3, 4};
    EXPECT_NEAR(ArithmeticAverage(first, second), 2.5, epsilon);

    first = {-1, 2, 8, 4};
    second = {0, 5, 3, 2};
    EXPECT_NEAR(ArithmeticAverage(first, second), 2.875, epsilon);
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    double expected = 10.247;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);

    first = {7, 4, 3, 13};
    second = {17, 6, 2, -2};
    expected = 18.16590212458495;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);
    // Write more test case

    first = {0, 0, 0, 0};
    second = {1, 1, 1, 1};

    expected = 2.0;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);

    first = {4, 4, 0, 8};
    second = {1, 2, 1, -2};
    expected = 10.678;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);

    first = {3, 3, 6, 0};
    second = {6, 9, 9, -2};
    expected = 7.615;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);
}
