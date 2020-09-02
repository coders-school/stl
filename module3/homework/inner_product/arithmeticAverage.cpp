#include <math.h>
#include <functional>
#include <numeric>
#include <vector>

#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    return std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0.0, std::plus<>(),
                              [&](const double& lhs, const double& rhs) { return ((lhs + rhs) / (vec1.size() + vec2.size())); });
}

double Distance(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    return sqrt(std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0.0, std::plus<>(),
                                   [](const double& lhs, const double& rhs) { return pow(lhs - rhs, 2); }));
}
