#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& a, const std::vector<int>& b) {
    auto sumA = std::accumulate(a.begin(), a.end(), 0);
    auto sumB = std::accumulate(b.begin(), b.end(), 0);
    return (sumA + sumB) / (a.size() + b.size());
}

double Distance(const std::vector<int>&, const std::vector<int>&) {
    return 0.0;
}
