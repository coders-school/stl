#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    double result = std::inner_product(
        first.begin(), first.end(), second.begin(), 0, std::plus<>{}, std::plus<>{});
    result /= (first.size() + second.size());
    return result;
}
double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    double result = std::inner_product(first.begin(), first.end(), second.begin(), 0, std::plus<>{},
                                       [](const auto& a, const auto& b) { return (a - b) * (a - b); });
    result = sqrt(result);
    return result;
}