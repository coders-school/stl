#include "arithmeticAverage.hpp"

#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& lhs, const std::vector<int>& rhs)
{
    auto sum = std::inner_product(lhs.begin(), lhs.end(), rhs.begin(), 0, std::plus<int>(),
                                  [](auto a, auto b) { return a + b; });
    return (double)sum / (double)(lhs.size() * 2);
}

double Distance(const std::vector<int>& lhs, const std::vector<int>& rhs)
{
    auto distance = std::inner_product(lhs.begin(), lhs.end(), rhs.begin(), 0.0, std::plus<double>(),
                                       [](auto a, auto b) { return pow(a - b, 2.0); });
    return sqrt(distance);
}