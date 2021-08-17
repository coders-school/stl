#include <cmath>
#include <iostream>
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
    if (first.size() != second.size()) {
        std::cout << "The both vectors must heave same size" << '\n';
        return 0;
    }

    if (first.size() == 1) {
        return std::abs (first[0] - second [0]);
    }

    double distA = std::sqrt (std::pow (std::abs (first[0] - second[0]), 2) + 
                              std::pow (std::abs (first[1] - second[1]), 2));
    while (size > 2) {
        distA = std::sqrt (std::pow (distA, 2) +
                           std::pow (std::abs (first[size-1] - second[size-1]), 2));
        --size;
    }
    return distA;
} 