#include "arithmeticAverage.hpp"
#include <algorithm>
#include <cmath>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    double sum = std::reduce(begin(first), end(first)) +
                 std::reduce(begin(second), end(second));
    return sum / (first.size() + second.size());
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.size() == 0 || first.size() != second.size()) {
        throw std::logic_error("collections of different sizes, or no items");
    }
    double distance = sqrt(std::transform_reduce(begin(first),
                                              end(first),
                                              begin(second),
                                              0,
                                              std::plus<>(),
                                              [](auto& first, auto& second) { return pow(second - first, 2); }));
    return distance;
}
