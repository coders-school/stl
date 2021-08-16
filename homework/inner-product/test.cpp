#include <vector>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    EXPECT_DOUBLE_EQ(ArithmeticAverage(first, second), 2.875);
    
    first = {-5, -3};
    second = {0, 12};
    EXPECT_DOUBLE_EQ(ArithmeticAverage(first, second), 1);

    first = {6, 2, 0};
    second = {6, -2, 3};
    EXPECT_DOUBLE_EQ(ArithmeticAverage(first, second), 2.5);

    first = {3, 1, 7, 3, 0, -2, 5, 1, 5};
    second = {5, 8, 2, 1, 1, -7, 3};
    EXPECT_DOUBLE_EQ(ArithmeticAverage(first, second), 2.25);
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    double expected = 10.246950765959598;
    EXPECT_DOUBLE_EQ(Distance(first, second), expected);
    
    first = {7, 4, 3, 13};
    second = {17, 6, 2, -2};
    expected = 18.16590212458495;
    EXPECT_DOUBLE_EQ(Distance(first, second), expected);
    
    first = {6, 2, 8};
    second = {-1, 5, 0};
    expected = 11.045361017187261;
    EXPECT_DOUBLE_EQ(Distance(first, second), expected);

    first = {1, 1, 1};
    second = {1, 1, 1};
    expected = 0;
    EXPECT_DOUBLE_EQ(Distance(first, second), expected);

    first = {5,1,-2};
    second = {3,1,6};
    expected = 8.2462112512353212;
    EXPECT_DOUBLE_EQ(Distance(first, second), expected);
}
