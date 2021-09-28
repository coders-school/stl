#include "arithmeticAverage.hpp"
#include <cmath>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    int sum1 = std::accumulate(begin(first), end(first), 0);
    int sum2 = std::accumulate(begin(second), end(second), 0);
    return double((sum1 + sum2) / double(first.size() + second.size()));
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    int n = first.size();
    double temporary{0};
    for (int i{0}; i < n; i++) {
        temporary = sqrt(std::pow(first[i] - second[i], 2) + std::pow(temporary, 2));
    }
    return temporary;
}

double DistanceRecurrent(const std::vector<int>& first, const std::vector<int>& second) {
    int n = first.size();
    if (n == 0) {
        return 0;
    }
    auto newFirst = std::vector<int> {begin(first), end(first) - 1};
    auto newSecond = std::vector<int> {begin(second), end(second) - 1};
    return sqrt(std::pow(first[n - 1] - second[n - 1], 2) + std::pow(DistanceRecurrent(newFirst, newSecond), 2));
}
