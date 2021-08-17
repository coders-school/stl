#include <algorithm>
#include <cmath>
#include <vector>
#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector <int>& first, const std::vector <int>& second) {
    double sum = 0;
    for (auto el : first) {
        sum += el;
    }
    for (auto el : second) {
        sum += el;
    }
    return sum / (first.size() + second.size());
}

double Distance(const std::vector <int>& first, const std::vector <int>& second) {
    int size = first.size();
    float distA = 0;
    distA = std::sqrt (std::pow (std::abs (first[0] - second[0]), 2) + 
                       std::pow (std::abs (first[1] - second[1]), 2));
    while (size > 2) {
        distA = std::sqrt (std::pow (distA, 2) +
                std::pow (std::abs (first[size-1] - second[size-1]), 2));
        --size;
    }
    return distA;
} 