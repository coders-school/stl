#include <vector>
#include <math.h>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

using CalculationTuple = std::tuple<std::vector<int>, std::vector<int>, double>;
using ExceptionTestTuple = std::tuple<std::vector<int>, std::vector<int>>;

class ResultsComparison {
public:
    bool cmp(double first, double second, double epsilon = 0.5) {
        return (fabs(first - second) < epsilon);
    }
};

class averageCalculationTestFixture : public ::testing::TestWithParam<CalculationTuple> , public ResultsComparison {
};

class distanceCalculationTestFixture : public ::testing::TestWithParam<CalculationTuple>, public ResultsComparison {
};

class averageExceptionTestFixture : public ::testing::TestWithParam<ExceptionTestTuple> {
};

class distanceExceptionTestFixture : public ::testing::TestWithParam<ExceptionTestTuple> {
};

TEST_P(averageCalculationTestFixture, ShouldCalculateArithmeticAverage) {
    auto [first, second, result] = GetParam();
    EXPECT_EQ(ArithmeticAverage(first, second), result);
    // EXPECT_TRUE(cmp(ArithmeticAverage(first, second), result));
}

TEST_P(averageExceptionTestFixture, ArithmeticAverageShouldThrowInvalidArgument) {
    auto [first, second] = GetParam();
    EXPECT_THROW(ArithmeticAverage(first, second), std::invalid_argument);
}

TEST_P(distanceCalculationTestFixture, ShouldCalculateDistance) {
    auto [first, second, result] = GetParam();
    EXPECT_TRUE(cmp(Distance(first, second), result));
}

TEST_P(distanceExceptionTestFixture, DistanceShouldThrowInvalidArgument) {
    auto [first, second] = GetParam();
    EXPECT_THROW(Distance(first, second), std::invalid_argument);
}

INSTANTIATE_TEST_CASE_P(
        averageCalculationTest,
        averageCalculationTestFixture,
        ::testing::Values(CalculationTuple{{-5, 4, 2, -5, 2, 4, 6, 7} , {3, 5, -2, 6, 7, -3, 6, 9} , 2.875},
                          CalculationTuple{{2, 3, 4}                  , {5, 6}                     , 4},
                          CalculationTuple{{2, 3}                     , {4, 5, 6}                  , 4},
                          CalculationTuple{{}                         , {6, 10}                    , 8},
                          CalculationTuple{{6, 10}                    , {}                         , 8}
        ));

INSTANTIATE_TEST_CASE_P(
        distanceCalculationTest,
        distanceCalculationTestFixture,
        ::testing::Values(CalculationTuple{{7, 4, 3} , {17, 6, 2} , 10.247},
                          CalculationTuple{{1, 2, 3, 4, 5} , {-1, 2, -3, 4, -5} , 11.832}
        ));

INSTANTIATE_TEST_CASE_P(
        averageExceptionTest,
        averageExceptionTestFixture,
        ::testing::Values(ExceptionTestTuple{{}, {}}
        ));

INSTANTIATE_TEST_CASE_P(
        distanceExceptionTest,
        distanceExceptionTestFixture,
        ::testing::Values(ExceptionTestTuple{{}, {}},
                          ExceptionTestTuple{{}, {1, 2, 3}},
                          ExceptionTestTuple{{4, 5}, {1, 2, 3}}
        ));
