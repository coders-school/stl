#include "arithmeticAverage.hpp"
#include <cmath>
#include <functional>
#include <numeric>
#include <stdexcept>
#include <vector>

double ArithmeticAverage(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("ArithmeticAverage - sizes of arguments are not equal");
    }
    if (vec1.size() == 0) {
        throw std::invalid_argument("ArithmeticAverage - empty vectors.");
    }
    return std::transform_reduce(vec1.cbegin(), vec1.cend(), vec2.cbegin(), 0, std::plus<>(), std::plus<>()) /
           static_cast<double>(vec1.size() * 2);
}

double Distance(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("Distance - points of different dimensions number provided.");
    }
    if (vec1.size() == 0) {
        throw std::invalid_argument("Distance - empty vectors.");
    }
    return std::sqrt(std::transform_reduce(vec1.cbegin(), vec1.cend(), vec2.cbegin(), 0, std::plus<>(),
                                           [](const int a, const int b) {
                                               return std::pow(a - b, 2);
                                           }));
}
