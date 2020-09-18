#include <cmath>
#include <vector>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

bool cmp(double first, double second, double epsilon = 0.5) {
    return (fabs(first - second) < epsilon);
}

using Vectors = std::tuple<std::vector<int>, std::vector<int>, double>;

struct arithmeticAverageTest : public ::testing::TestWithParam<Vectors> {};

INSTANTIATE_TEST_SUITE_P(SomeVectors, 
                        arithmeticAverageTest,
                        ::testing::Values(Vectors{{-5, 4, 2, -5, 2, 4, 6, 7}, {3, 5, -2, 6, 7, -3, 6, 9}, 2.875},
                                          Vectors{{1}, {1}, 1.0}));

TEST_P(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    auto [first, second, result] = GetParam();
    EXPECT_TRUE(cmp(ArithmeticAverage(first, second), result));
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    EXPECT_TRUE(cmp(Distance(first, second), 10.247));
}
