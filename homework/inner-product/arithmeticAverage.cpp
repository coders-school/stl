#include <cmath>
#include <numeric>

#include "arithmeticAverage.hpp"

double ArithmeticAverage(std::vector<int>& v1, std::vector<int>& v2) {
    double sum = std::reduce(v1.begin(), v1.end()) + std::reduce(v2.begin(), v2.end());
    return sum / (v1.size() + v2.size());
}

double Distance(std::vector<int>& v1, std::vector<int>& v2) {
    return sqrt(std::inner_product(v1.begin(), v1.end(), v2.begin(), 0, std::plus<>(), []( const auto& point1, const auto& point2) {
                                               return std::pow(point1 - point2, 2);
                                           }));
}