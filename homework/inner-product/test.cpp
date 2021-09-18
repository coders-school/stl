#include <vector>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

constexpr double epsilon = 0.001;

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    EXPECT_NEAR(ArithmeticAverage(first, second), 2.875, epsilon);
    // Write more test case

    first = {-5, 4, 2};
    second = {3, 5,};
    EXPECT_NEAR(ArithmeticAverage(first, second), 1.8, epsilon);

    first = {-5, 4, 2};
    second = {3, 5,-2, 6, 7};
    EXPECT_NEAR(ArithmeticAverage(first, second), 2.5, epsilon);

    first = {-5, 4, 2};
    second.clear();
    EXPECT_NEAR(ArithmeticAverage(first, second), 0.333, epsilon);

    first = {0};
    second = {0};
    EXPECT_NEAR(ArithmeticAverage(first, second), 0, epsilon);

    first.clear();
    second.clear();
    EXPECT_NEAR(ArithmeticAverage(first, second), 0, epsilon);

}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    double expected = 10.247;
    EXPECT_NEAR(Distance(first, second), expected, epsilon);
    
    first = {7, 4, 3, 13};
    second = {17, 6, 2, -2};
    expected = 18.16590212458495;
    EXPECT_NEAR(Distance(first, second), expected, 0.00001);
    // Write more test case

    first = {7, 4};
    second = {17};
    expected = 10.77032961;
    EXPECT_NEAR(Distance(first, second), expected, 0.00001);

    first = {0};
    second = {0};
    expected = 0;
    EXPECT_NEAR(Distance(first, second), expected, 0.00001);

    first = {3,4};
    second.clear();
    expected = 5;
    EXPECT_NEAR(Distance(first, second), expected, 0.00001);

    first.clear();
    second.clear();
    expected = 5;
    EXPECT_NEAR(Distance(first, second), 0, 0.00001);

}
