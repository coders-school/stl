#include "arithmeticAverage.hpp"
#include <cmath>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    return std::inner_product(first.cbegin(),
                              first.cend(),
                              second.cbegin(),
                              0,
                              std::plus<int>{},
                              std::plus<int>{}) /
           static_cast<double>(first.size() + second.size());
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    auto result = std::inner_product(first.cbegin(),
                                     first.cend(),
                                     second.cbegin(),
                                     0.0,
                                     std::plus<double>{},
                                     [](double lhs, double rhs) {
                                         return std::pow(lhs - rhs, 2.0);
                                     });
    return std::sqrt(result);
}
