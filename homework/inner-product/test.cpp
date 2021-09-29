#include <algorithm>
#include <vector>
#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

constexpr double epsilon = 0.001;

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    double expected = 2.875;
    EXPECT_NEAR(ArithmeticAverage(first, second), expected, epsilon);

    first = {-5, 4, 2};
    second = {3, 5, -2, 6, 7, -3, 6, 9};
    expected = 2.909;
    EXPECT_NEAR(ArithmeticAverage(first, second), expected, epsilon);

    first = {10, 10, 10};
    second = {-10, -10, -10};
    expected = 0;
    EXPECT_NEAR(ArithmeticAverage(first, second), expected, epsilon);

    first = {};
    second = {};
    expected = 0;
    EXPECT_NEAR(ArithmeticAverage(first, second), expected, epsilon);
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

    first = {};
    second = {};
    expected = 0;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);

    first = {1, 2, 3};
    second = {1, 2, 3};
    expected = 0;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);

    first.resize(1000);
    std::fill(begin(first), end(first), -10);
    second.resize(1000);
    std::fill(begin(second), end(second), 10);
    expected = 632.456;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);
}
