#include <vector>
#include <math.h>

#include "arithmeticAverage.hpp"
#include "gtest/gtest.h"

bool cmp(double first, double second, double epsilon = 0.5) {
    return (fabs(first - second) < epsilon);
}

struct TestData {
  TestData(std::vector<int> first, std::vector<int> second, double result)
      : first_{first}, second_{second}, result_{result} {};
  std::vector<int> first_;
  std::vector<int> second_;
  double result_;
};

class arithmeticAverageTest : public ::testing::TestWithParam<TestData> {};
class distanceTest : public ::testing::TestWithParam<TestData> {};

TEST_P(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
  EXPECT_TRUE(cmp(ArithmeticAverage(GetParam().first_, GetParam().second_),
                  GetParam().result_));
}

INSTANTIATE_TEST_SUITE_P(someName, arithmeticAverageTest,
                         ::testing::Values(TestData({1}, {1,100}, 1.0),
                                           TestData({-5, 4, 2, -5, 2, 4, 6, 7}, {3, 5, -2, 6, 7, -3, 6, 9}, 2.875),
                                           TestData({10,20,30}, {1,2,3}, 11),
                                           TestData({1,2,3,4}, {1,2,3,4}, 2.5)
                                           ));


TEST_P(distanceTest, ShouldCalculateDistance) {
  EXPECT_TRUE(cmp(Distance(GetParam().first_, GetParam().second_),
                  GetParam().result_));
}

INSTANTIATE_TEST_SUITE_P(someName, distanceTest, 
                        ::testing::Values(
                            TestData({7, 4, 3}, {17, 6, 2}, 10.247),
                            TestData({7, 7, 7}, {7, 7, 7}, 0),
                            TestData({0, 0}, {1, 1}, 1.14142)
                            ));

