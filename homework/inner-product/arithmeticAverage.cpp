#include "arithmeticAverage.hpp"
#include <cmath>
#include <iostream>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.size() != second.size() && first.size() != 0) {
        return 0;
    }
    return std::inner_product(first.begin(),
                              first.end(),
                              second.begin(),
                              0,
                              std::plus<>(),
                              std::plus<>()) /
           static_cast<double>(first.size() * 2);
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.size() != second.size() && first.size() != 0) {
        return 0;
    }
    return std::sqrt(std::inner_product(first.begin(),
                                        first.end(),
                                        second.begin(),
                                        0,
                                        std::plus<>(),
                                        [](const auto lhs, const auto rhs) {
                                            return std::pow(lhs - rhs, 2);
                                        }));
}
