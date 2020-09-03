#include "arithmeticAverage.hpp"

#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.size() * second.size() == 0 || first.size() != second.size()) {
        return 0;
    }

    return std::inner_product(first.begin(), first.end(), second.begin(), 0,
                              std::plus<>(), std::plus<>()) /
           (first.size() * 2.0);
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    return sqrt(std::inner_product(
        first.begin(), first.end(), second.begin(), 0, std::plus<>(),
        [](const auto& lhs, const auto& rhs) { return (lhs - rhs) * (lhs - rhs); }));
}
