#include "arithmeticAverage.hpp"

#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    return std::inner_product(first.cbegin(),
                              first.cend(),
                              second.cbegin(),
                              0.0,
                              std::plus<int>{},
                              std::plus<int>{}) / (first.size() + second.size());
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    return std::sqrt(std::inner_product(first.cbegin(),
                              first.cend(),
                              second.cbegin(),
                              0.0,
                              std::plus<int>{},
                              [](const auto& f, const auto& s) {
                                  return (f - s) * (f - s);
                              }));
}
