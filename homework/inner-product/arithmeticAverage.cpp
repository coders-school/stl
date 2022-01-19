#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int> & v1, const std::vector<int> & v2)
{
    double result = (std::accumulate(v1.begin(), v1.end(), 00) + std::accumulate(v2.begin(), v2.end(), 0)) / ((double)v1.size() + (double)v2.size());
    return result;
}

double Distance(const std::vector<int> & v3, const std::vector<int> & v4)
{
    auto lambda = [] (auto a, auto b) { return pow((a-b), 2); };
    double result = pow(std::inner_product(v3.begin(), v3.end(), v4.begin(), 0, std::plus<>(), lambda), 0.5);
    return result;
}
