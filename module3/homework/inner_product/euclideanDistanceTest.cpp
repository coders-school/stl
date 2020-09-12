#include <gtest/gtest.h>

#include "euclideanDistance.hpp"

TEST(EuclideanDistanceTest, ShouldCalculateBetweenMultiplePoints) {
    ASSERT_NEAR(euclideanDistance({ 0, 0, 0 }, { 0, 0, 0 }), 0, 0.0001);
    ASSERT_NEAR(euclideanDistance({ 7, 4, 3 }, { 17, 6, 2 }), 10.247, 0.0001);
    ASSERT_NEAR(euclideanDistance({ 14, 1 }, { 12, 4 }), 3.60555, 0.0001);
    ASSERT_NEAR(euclideanDistance({ -7, 4, -3 }, { 17, -6, 2 }), 26.476405, 0.0001);
    ASSERT_NEAR(euclideanDistance({ 2, 7, 4, 3 }, { -6, 17, 6, 2 }), 13, 0.0001);
}
