#include <algorithm>
#include <cmath>
#include <vector>
#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector <int>& first, const std::vector <int>& second) {
    int sum = 0;
    for (auto el : first) {
        sum += el;
    }
    for (auto el : second) {
        sum += el;
    }
        return sum / (first.size() + second.size());
}

double Distance(const std::vector <int>& first, const std::vector <int>& second) {
    float distA = 0;
    float distB = 0;
    //float distC = 0;
    distA = std::sqrt (std::abs (first[1] - second[1]) * (first[1] - second[1]) + 
                       std::abs (first[2] - second[2]) * (first[2] - second[2]));
    distB = std::sqrt (std::abs (first[2] - second[2]) * (first[2] - second[2]) + 
                       std::abs (first[3] - second[3]) * (first[3] - second[3]));
                       

    return std::sqrt ((distA * distA) + (distB * distB));
}

// std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
// std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};