#include "arithmeticAverage.hpp"
#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    double sumOfElements = static_cast<double>(first.size() + second.size());
    auto average = std::inner_product(first.begin(), first.end(),
                                      second.begin(), 0,
                                      std::plus<int>(), std::plus<int>()) / sumOfElements;
    return average;
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    auto distance = std::sqrt(std::inner_product(first.begin(), first.end(), second.begin(),
                    0, std::plus<int>(),
                    [](const auto& first, const auto& second) {
                        return std::pow(std::abs(first - second), 2);
                    }));
}
