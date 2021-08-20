#include "arithmeticAverage.hpp"

#include <functional>

double ArithmeticAverage(const std::vector<int> &first, const std::vector<int> &second) {
    return std::inner_product(first.begin(), first.end(), second.begin(), 0,
                              std::plus<>(), std::plus<>()) /
           static_cast<double>(first.size() + second.size());
}
double Distance(const std::vector<int> &first, const std::vector<int> &second) {
    double result = std::sqrt(std::inner_product(first.begin(), first.end(), second.begin(), 0,
                                                 std::plus<int>(), [](const auto &lhs, const auto &rhs) {
                                                     return std::pow(std::abs(lhs - rhs), 2);
                                                 }));
    return std::ceil(result * 1000.0) / 1000.0;
}