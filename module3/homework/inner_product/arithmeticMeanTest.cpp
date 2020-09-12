#include <gtest/gtest.h>

#include "arithmeticMean.hpp"

TEST(ArithmeticMeanTest, ShouldCalculateForTwoSameLengthVectors) {
    ASSERT_NEAR(arithmeticMean({ 1, 2, 3, 4 }, {1, 2, 3, 4 }), 2.5, 0.0001);
    ASSERT_NEAR(arithmeticMean({ -9, -2, -3 }, {1, 1, 3}), -1.5, 0.0001);
    ASSERT_NEAR(arithmeticMean({-99, -20, -3, 6}, {7, 10, 3, -6}), -12.75, 0.0001);
    ASSERT_NEAR(arithmeticMean({0, 10, -6, 0}, {-7, 0, 99, 36}), 16.5, 0.0001);
}
