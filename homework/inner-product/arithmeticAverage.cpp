#pragma once
#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    double sum = std::accumulate(first.begin(), first.end(),0) + std::reduce(second.begin(), second.end(),0);
    return  sum / (first.size() + second.size());
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    return std::sqrt(std::inner_product(first.begin(), first.end(), second.begin(), 0,std::plus<>(), 
    [](auto x, auto y){return std::pow(y - x, 2); }));
}