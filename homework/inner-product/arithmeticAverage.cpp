#include "arithmeticAverage.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& firstVector, const std::vector<int>& secondVector) {
    return static_cast<double>(std::reduce(firstVector.cbegin(), firstVector.cend(), 0)
           + std::reduce(secondVector.cbegin(), secondVector.cend(), 0))
           / (firstVector.size() + secondVector.size());
}

double Distance(const std::vector<int>& firstVector, const std::vector<int>& secondVector) {
    if (firstVector.size() == secondVector.size()) {
        std::vector<int> squaredDifferences(firstVector.size());
        std::transform(firstVector.cbegin(),
                       firstVector.cend(),
                       secondVector.cbegin(),
                       squaredDifferences.begin(),
                       [](auto first, auto second){
                           return std::pow(first - second, 2);
                       });
        return std::sqrt(std::reduce(squaredDifferences.cbegin(), squaredDifferences.cend(), 0));
    }
    std::cerr << "Wrong input data.\n";
    return -1.0;
}
