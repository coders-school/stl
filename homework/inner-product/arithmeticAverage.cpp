#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& a, const std::vector<int>& b) {
    auto sumA = std::accumulate(a.begin(), a.end(), 0.0);
    auto sumB = std::accumulate(b.begin(), b.end(), 0.0);
    return (sumA + sumB) / (a.size() + b.size());
}

double Distance(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> ab = {};
    std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(ab), std::minus<int>());

    int sum = 0;
    for (const auto& el : ab) {
        sum += el * el;
    }

    return sqrt(sum);
}
