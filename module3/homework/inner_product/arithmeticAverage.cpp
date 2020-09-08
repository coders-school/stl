#include "arithmeticAverage.hpp"
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    int sumOfElements = first.size() + second.size();
    auto average = std::inner_product(first.begin(), first.end(),
                                      second.begin(), 0,
                                      std::plus<int>(), std::plus<int>()) / sumOfElements;
    return average;
}
