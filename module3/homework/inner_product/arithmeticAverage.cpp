#include "arithmeticAverage.hpp"

#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

double ArithmeticAverage(std::vector<int> first, std::vector<int> second) {
    auto sum = std::inner_product(first.begin(), first.end(), second.begin(), 0,
                       std::plus<>(), std::plus<>());
    return static_cast<double>(sum) / (first.size() + second.size());
}

double Distance(std::vector<int> first, std::vector<int> second) {
    return 0;
}
