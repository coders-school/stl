#include "arithmeticAverage.hpp"
#include "distance.hpp"
#include "gtest/gtest.h"

#include <cmath>
#include <vector>


bool cmp(double first, double second, double epsilon = 0.5) {
    return (fabs(first - second) < epsilon);
}

TEST(arithmeticAverageTest, ShouldCalculateArithmeticAverage) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    EXPECT_TRUE(cmp(ArithmeticAverage{}(first, second), 2.875));
    
    std::vector<int> third{4, 4, 4, 4, 4};
    std::vector<int> fourth{4, 4, 4, 4, 4};
    EXPECT_TRUE(cmp(ArithmeticAverage{}(third, fourth), 4));

    std::vector<int> fifth{0, 0, 0, 4, 4};
    std::vector<int> sixth{4, 4, 4, 0, 0};
    EXPECT_TRUE(cmp(ArithmeticAverage{}(fifth, sixth), 2));
    // Write more test case
}

TEST(arithmeticAverageTest, ShouldCalculateDistance) {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    EXPECT_TRUE(cmp(Distance{}(first, second), 10.247));
    // (7−17)² + (4−6)² + (3−2)² = sqrt105
    
    std::vector<int> third{0, 0, 0};
    std::vector<int> fourth{0, 0, 0};
    EXPECT_TRUE(cmp(Distance{}(third, fourth), 0));

    // Write more test case
    
}
