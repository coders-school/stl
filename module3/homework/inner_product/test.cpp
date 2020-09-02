#include <cmath>
#include <tuple>
#include <vector>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

bool cmp(double first, double second, double epsilon = 0.5) {
    return (fabs(first - second) < epsilon);
}

class ArithmeticAverageTests
    : public ::testing::TestWithParam<
          std::tuple<std::vector<int>, std::vector<int>, double>> {};

TEST_P(ArithmeticAverageTests, ShouldCalculateArithmethicAverage) {
    auto [first, second, expectedAverage] = GetParam();
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), expectedAverage))
        << ArithmeticAverage(first, second) << ", " << expectedAverage;
};

INSTANTIATE_TEST_SUITE_P(
    ShouldCalculateArithmeticAverage,
    ArithmeticAverageTests,
    testing::Values(
        std::tuple<std::vector<int>, std::vector<int>, double>{
            {-5, 4, 2, -5, 2, 4, 6, 7},
            {3, 5, -2, 6, 7, -3, 6, 9},
            2.875},
        std::tuple<std::vector<int>, std::vector<int>, double>{{1, 2, 3, 4, 5},
                                                               {1, 2, 3, 4, 5},
                                                               3},

        std::tuple<std::vector<int>, std::vector<int>, double>{{1, 2, 3},
                                                               {1, 2, 3},
                                                               2},
        std::tuple<std::vector<int>, std::vector<int>, double>{{0}, {0}, 0}));


TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    EXPECT_TRUE(cmp(Distance(first, second), 10.247));
    // Write more test case
}
