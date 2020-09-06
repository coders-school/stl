#include "arithmeticAverage.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(std::vector<int> first, std::vector<int> second) {
    return (double)std::inner_product(first.begin(), first.end(), second.begin(), 0, std::plus<>(), std::plus<>()) /
           (first.size() + second.size());
}

double Distance(std::vector<int> first, std::vector<int> second) {
    return sqrt(std::inner_product(first.cbegin(), first.cend(), second.cbegin(), 0.0, std::plus<>(),
                                   [](const auto& el1, const auto& el2) {
                                       return pow(el1 - el2, 2);
                                       }));
}
