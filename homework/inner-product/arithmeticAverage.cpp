#include "arithmeticAverage.hpp"
#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    return (double)(std::accumulate(first.begin(), first.end(), 0) + std::accumulate(second.begin(), second.end(), 0)) / (first.size() + second.size());
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    return std::sqrt(std::inner_product(first.begin(),
                                        first.end(),
                                        second.begin(),
                                        0,
                                        std::plus<>(),
                                        [](auto a, auto b) { return (b - a) * (b - a); }));
}
