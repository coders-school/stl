#include "arithmeticAverage.hpp"
#include <iostream>
#include <cmath>
double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    double res = std::accumulate(first.begin(), first.end(), 0.0) + std::accumulate(second.begin(), second.end(), 0.0);
    return res / (first.size() + second.size());
}
double Distance(const std::vector<int>& first, const std::vector<int>& second){
    double res{};
    for (size_t i = 0; i < first.size();i++){
        res+=(second[i]-first[i])*(second[i]-first[i]);
    }
    return sqrt(res);
}