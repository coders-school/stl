#include "arithmeticAverage.hpp"
// #include <algorithm>
#include <iostream>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    int sum1 = std::accumulate(begin(first), end(first), 0);
    int sum2 = std::accumulate(begin(second), end(second), 0);
    return double((sum1 + sum2) / double(first.size() + second.size()));
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    return 0;
}
