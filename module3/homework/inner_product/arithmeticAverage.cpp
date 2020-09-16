#include "arithmeticAverage.hpp"

#include <algorithm>
#include <functional>
#include <math.h>
#include <numeric>
#include <stdexcept>
#include <vector>

double ArithmeticAverage(std::vector<int> first, std::vector<int> second) {
    if (first.size() == 0 || second.size() == 0) {
        throw std::invalid_argument("Vectors cannot be empty");
    }
    else if (first.size() != second.size()) {
        throw std::invalid_argument("Both vectors should be the same size");
    }
    
    auto sum = std::inner_product(first.cbegin(), first.cend(), second.cbegin(), 0,
                                 std::plus<>(), std::plus<>());

    return static_cast<double>(sum) / (first.size() + second.size());
}

double Distance(std::vector<int> first, std::vector<int> second) {
    if (first.size() == 0 || second.size() == 0) {
        throw std::invalid_argument("Vectors cannot be empty");
    }
    else if (first.size() != second.size()) {
        throw std::invalid_argument("Both vectors should be the same size");
    }

    auto sum = std::inner_product(first.cbegin(), first.cend(), second.cbegin(), 0,
                                 std::plus<>(), [](const auto& x, const auto& y){
                                     return pow((y - x), 2);
                                 });

    return sqrt(static_cast<double>(sum));
}
