#include "arithmeticAverage.hpp"

#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& vector1, const std::vector<int>& vector2) {
    double sum;
    double result;
    sum = std::inner_product(vector1.begin(), vector1.end(), vector2.begin(), 0, std::plus<int>(), std::plus<int>());
    result = sum / (vector1.size() + vector2.size());
    return result;
}

double distance_square(int point_x, int point_y) {
    return pow((point_x - point_y), 2);
}

double Distance(const std::vector<int>& vector1, const std::vector<int>& vector2) {
    double result;
    result = std::inner_product(vector1.begin(), vector1.end(), vector2.begin(), 0, std::plus<int>(), distance_square);
    result = std::sqrt(result);
    return result;
}
