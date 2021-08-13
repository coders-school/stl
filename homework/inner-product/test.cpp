#include <stdexcept>
#include <vector>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    EXPECT_DOUBLE_EQ(ArithmeticAverage(first, second), 2.875);

    first = {2, 2, 2};
    second = {2, 2, 2};
    EXPECT_DOUBLE_EQ(ArithmeticAverage(first, second), 2.0);

    first = {0, 0};
    second = {0, 0};
    EXPECT_DOUBLE_EQ(ArithmeticAverage(first, second), 0.0);

    first = {-5, 4, 2, -5, 2, 4, 6, 7};
    second = {3, 5, -2, 6, 7, -3, 6, 9, 10};
    try {
        ArithmeticAverage(first, second);
        FAIL() << "Expected std::invalid_argument";
    } catch (const std::invalid_argument& err) {
        EXPECT_EQ(err.what(), std::string("ArithmeticAverage - sizes of arguments are not equal"));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    first = {};
    second = {};
    try {
        ArithmeticAverage(first, second);
        FAIL() << "Expected std::invalid_argument";
    } catch (const std::invalid_argument& err) {
        EXPECT_EQ(err.what(), std::string("ArithmeticAverage - empty vectors."));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    // I had to change expected value to more precise one ( original one 10.247 )
    double expected = 10.246950765959598;
    EXPECT_DOUBLE_EQ(Distance(first, second), expected);

    first = {7, 4, 3, 13};
    second = {17, 6, 2, -2};
    expected = 18.16590212458495;
    EXPECT_DOUBLE_EQ(Distance(first, second), expected);

    first = {-5, 4, 2, -5, 2, 4, 6, 7};
    second = {3, 5, -2, 6, 7, -3, 6, 9, 10};
    try {
        Distance(first, second);
        FAIL() << "Expected std::invalid_argument";
    } catch (const std::invalid_argument& err) {
        EXPECT_EQ(err.what(), std::string("Distance - points of different dimensions number provided."));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    first = {};
    second = {};
    try {
        Distance(first, second);
        FAIL() << "Expected std::invalid_argument";
    } catch (const std::invalid_argument& err) {
        EXPECT_EQ(err.what(), std::string("Distance - empty vectors."));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }
}
