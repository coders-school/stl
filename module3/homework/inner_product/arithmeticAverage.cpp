#include "arithmeticAverage.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    auto res = std::inner_product(
        lhs.begin(), lhs.end(), rhs.begin(), 0, [](int x, int y) { return x + y; }, [](int x, int y) { return x + y; });
    return (double)res / (lhs.size() + rhs.size());
}

double Distance(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    auto res = std::inner_product(
        lhs.begin(), lhs.end(), rhs.begin(), 0, [](int x, int y) { return y + x; },
        [](int x, int y) { return (y - x) * (y - x); });
    return std::sqrt(res);
}