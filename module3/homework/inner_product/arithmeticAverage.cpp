#include "arithmeticAverage.hpp"

#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    return std::inner_product(first.cbegin(), first.cend(), second.cbegin(), 0.0, std::plus<>(), std::plus<>()) /
           (first.size() + second.size());
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    return sqrt(std::inner_product(first.cbegin(), first.cend(), second.begin(), 0.0, std::plus<>(),
                                   [](auto lhs, auto rhs) { return pow(lhs - rhs, 2); }));
}
