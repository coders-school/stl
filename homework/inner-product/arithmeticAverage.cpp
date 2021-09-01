#include "arithmeticAverage.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    double firstSum =  std::accumulate(first.begin(), first.end(), 0, std::plus<>{}); 
    double secondSum = std::accumulate(second.begin(), second.end(), 0, std::plus<>{});
    return std::plus<>{}(firstSum, secondSum) / (first.size() + second.size());
}


double Distance(const std::vector<int>& first, const std::vector<int>& second) {
        double sum = 0;
        for (size_t i {0}; i < first.size(); ++i) {
            sum += std::pow(first[i] - second[i], 2);
        }
        return std::sqrt(sum);;
}