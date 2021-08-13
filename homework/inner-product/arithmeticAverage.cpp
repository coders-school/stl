#include "arithmeticAverage.hpp"
#include <functional>
#include <numeric>
#include <stdexcept>
#include <vector>
#include <cmath>

double ArithmeticAverage(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("ArithmeticAverage - arguments are not equal in size.");
    }
    return std::transform_reduce(vec1.cbegin(), vec1.cend(), vec2.cbegin(), 0, std::plus<>(), std::plus<>()) /
           static_cast<double>(vec1.size() * 2);
}

double Distance(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::invalid_argument("Distance - different dimension number of provided points.");
    }
    return std::sqrt(std::transform_reduce(vec1.cbegin(), vec1.cend(), vec2.cbegin(), 0, std::plus<>(),
        [](const int a, const int b) {
            return std::pow(a - b, 2);
        }));
}
