#include "arithmeticAverage.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

double ArithmeticAverage(std::vector<int> first, std::vector<int> second) {
    return (double)std::inner_product(first.begin(), first.end(), second.begin(), 0, std::plus<>(), std::plus<>()) /
           (first.size() + second.size());
}

double Distance(std::vector<int> first, std::vector<int> second) {
    double distance;

    return distance;
}
