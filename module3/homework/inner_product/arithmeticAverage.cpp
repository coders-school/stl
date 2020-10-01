#include "arithmeticAverage.hpp"
#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    const double sumOfElements = static_cast<double>(first.size() + second.size());
    const auto average = std::inner_product(first.cbegin(), first.cend(),
                                      second.cbegin(), 0,
                                      std::plus<int>(), std::plus<int>()) / sumOfElements;
    return average;
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    const auto distance = std::sqrt(std::inner_product(first.cbegin(), first.cend(), second.cbegin(),
                    0, std::plus<int>(),
                    [](const auto& first, const auto& second) {
                        return std::pow(std::abs(first - second), 2);
                    }));
    return distance;
}
