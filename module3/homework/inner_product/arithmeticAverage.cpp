#include "arithmeticAverage.hpp"

#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    auto result = std::inner_product(first.begin(), first.end(), second.begin(), 0, std::plus<int>(), std::plus<int>()) /
                  static_cast<double>(first.size() + second.size());
    return result;
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    //auto result = std::inner_product(first.begin(), first.end(), second.begin(), 0, std::plus<int>(), std::minus<int>())
    auto result = std::sqrt(std::inner_product(first.begin(), first.end(), second.begin(), 0, std::plus<int>(),
                                               [](const auto& lhs, const auto& rhs) { return std::pow(std::abs(lhs - rhs), 2); }));

    return result;
}
