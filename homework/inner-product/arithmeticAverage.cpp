#include "arithmeticAverage.hpp"
#include <cmath>
#include <numeric>

double ArithmeticAverage(const std::vector<int> &first, const std::vector<int> &second) {
    return (std::reduce(first.begin(), first.end(), 0) + std::reduce(second.begin(), second.end(), 0)) / static_cast<double>(first.size() + second.size());
}

double Distance(const std::vector<int> &first, const std::vector<int> &second) {
    double sum = 0.0;
    for (size_t i = 0; i < first.size(); ++i) {
        sum += std::pow(first[i] - second[i], 2);
    }

    return std::sqrt(sum);
}
