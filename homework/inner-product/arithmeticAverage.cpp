#include "arithmeticAverage.hpp"
#include <cmath>
#include <iostream>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.size() != second.size() && first.size() != 0) {
        return 0;
    }
    return std::inner_product(first.begin(),
                              first.end(),
                              second.begin(),
                              0,
                              std::plus<>(),
                              std::plus<>()) /
           static_cast<double>(first.size() * 2);
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    // int size = first.size();
    // if (first.size() != second.size()) {
    //     std::cout << "The both vectors must heave same size" << '\n';
    //     return 0;
    // }

    // if (first.size() == 1) {
    //     return std::abs(first[0] - second[0]);
    // }

    // double distA = std::sqrt(std::pow(std::abs(first[0] - second[0]), 2) +
    //                          std::pow(std::abs(first[1] - second[1]), 2));
    // while (size > 2) {
    //     distA = std::sqrt(std::pow(distA, 2) +
    //                       std::pow(std::abs(first[size - 1] - second[size - 1]), 2));
    //     --size;
    // }
    // return distA;
    if (first.size() != second.size() && first.size() != 0) {
        return 0;
    }
    return std::sqrt(std::inner_product(first.begin(),
                              first.end(),
                              second.begin(),
                              0,
                              std::plus<>(),
                              [](const auto lhs, const auto rhs) {
                                  return std::pow(lhs - rhs, 2);
                              }));
}