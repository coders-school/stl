#include <cmath>
#include <functional>
#include <numeric>

#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    return std::inner_product(first.begin(), first.end(), second.begin(), 0,
                              std::plus<int>(), std::plus<int>()) /
           (first.size() * 2.0);
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    return sqrt(std::inner_product(first.begin(), first.end(), second.begin(), 0, std::plus<int>(),
                                   [](auto lhs, auto rhs) { return std::pow(rhs - lhs, 2); }));
}
