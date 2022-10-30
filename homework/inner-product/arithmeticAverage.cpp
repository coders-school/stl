#include "arithmeticAverage.hpp"
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>

double ArithmeticAverage(std::vector<int>& first, std::vector<int>& second) {
    auto sum = std::accumulate(first.begin(), first.end(), 0.0);
    sum = std::accumulate(second.begin(), second.end(), sum);
    auto result = sum / (second.size() + first.size());
    return result;
}

template <class T>
struct Factor {
    constexpr T operator()(const T& lhs, const T& rhs) const {
        return pow(rhs - lhs, 2);
    }
};

double Distance(std::vector<int>& first, std::vector<int>& second) {
    int sum = std::inner_product(first.begin(), first.end(), second.begin(), 0,
                                 std::plus<>(), Factor<double>());
    auto result = sqrt(sum);
    return result;
}
