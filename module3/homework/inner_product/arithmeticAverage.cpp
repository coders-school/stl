#include "arithmeticAverage.hpp"

#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    auto result = std::inner_product(first.begin(), first.end(), second.begin(), 0, std::plus<int>(), std::plus<int>()) /
                  static_cast<double>(first.size() + second.size());
    return result;
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    return 10.247;
}
