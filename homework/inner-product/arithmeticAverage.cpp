#include "arithmeticAverage.hpp"
#include <iostream>
#include <numeric>
#include <functional>
#include <cmath>

double ArithmeticAverage(std::vector<int>& first, std::vector<int>& second)
{
    auto r1 = std::accumulate(first.begin(), first.end(), 0.0);
    auto sum = std::accumulate(second.begin(), second.end(), r1);
    auto result = sum / (second.size() + first.size());
    return result;
}

double Distance(std::vector<int>& first, std::vector<int>& second)
{
    std::vector<double> factors;
    auto first_it = first.begin();
    auto second_it = second.begin();
    for(; first_it != first.end(); ++first_it, ++second_it)
    {
        auto factor = pow(*second_it - *first_it, 2);      
        factors.push_back(factor);
    }
    auto sum = std::accumulate(factors.begin(), factors.end(), 0.0); 
    auto result = sqrt(sum); 
    return result;
}
