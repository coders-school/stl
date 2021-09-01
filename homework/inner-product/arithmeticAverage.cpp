#include "arithmeticAverage.hpp"

#include <algorithm>
#include <cmath>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    double firstSum =  std::accumulate(first.begin(), first.end(), 0); 
    double secondSum = std::accumulate(second.begin(), second.end(), 0);
    return (firstSum + secondSum) / (first.size() + second.size());
}


double Distance(const std::vector<int>& first, const std::vector<int>& second){
    if(first.size() == second.size()){
        std::vector<int> squaredDiff(first.size());
        std::transform(first.cbegin(),
                       first.cend(),
                       second.cbegin(),
                       squaredDiff.begin(),
                       [](auto first, auto second){
                           return std::pow(first - second, 2);
                       });
        return std::sqrt(std::accumulate(squaredDiff.begin(), squaredDiff.end(), 0)); 
    }
    
    return 0.0;
}