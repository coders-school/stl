
#include "arithmeticAverage.hpp"

#include <cmath>
#include <numeric>
#include <stdexcept>

double ArithmeticAverage(
    const std::vector<int>& first,
    const std::vector<int>& second) {
    if (first.size() != second.size()) {
        throw std::invalid_argument("Vectors must have equal sizes");
    }

    if (first.empty()) {
        return 0.0;
    }

    double sum = std::inner_product(
        first.begin(),
        first.end(),
        second.begin(),
        0.0,
        std::plus<>(),
        [](int a, int b) {
            return static_cast<double>(a + b);
        });

    return sum / (first.size() + second.size());
}

double Distance(
    const std::vector<int>& first,
    const std::vector<int>& second) {
    if (first.size() != second.size()) {
        throw std::invalid_argument("Vectors must have equal sizes");
    }

    double sum = std::inner_product(
        first.begin(),
        first.end(),
        second.begin(),
        0.0,
        std::plus<>(),
        [](int a, int b) {
            double difference = static_cast<double>(a) - b;
            return difference * difference;
        });

    return std::sqrt(sum);
}
