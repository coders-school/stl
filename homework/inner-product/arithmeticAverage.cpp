#include "arithmeticAverage.hpp"

#include <cmath>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.empty() && second.empty()) {
        return 0.0;
    }

    double average = std::reduce(first.cbegin(), first.cend(),
                                 std::reduce(second.cbegin(), second.cend(), 0));
    return average / static_cast<double>(first.size() + second.size());
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.size() != second.size()) {
        return 0.0;
    }

    double squaredSumValue = std::transform_reduce(first.cbegin(), first.cend(), second.cbegin(), 0.0, std::plus{},
                                                   [](const auto& lhs, const auto& rhs) {
                                                       auto diff = lhs - rhs;
                                                       return diff * diff;
                                                   });
    return std::sqrt(squaredSumValue);
}
