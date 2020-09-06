#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.empty() && second.empty()) {
        return 0.0;
    }

    auto elemNum = first.size() + second.size();
    double result = std::inner_product(first.begin(), first.end(), second.begin(), 0,
                                       std::plus<int>(), std::plus<int>());

    return result / elemNum;
}
double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.size() != second.size() || first.empty()) {
        return 0.0;
    }
    auto euclidesLambda = [](const auto& lhs, const auto& rhs) { return std::pow(std::abs(lhs - rhs), 2); };

    double result = std::sqrt(std::inner_product(first.begin(), first.end(), second.begin(), 0,
                                                 std::plus<int>(), euclidesLambda));
    return result;
}