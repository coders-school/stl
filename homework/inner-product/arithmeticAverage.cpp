

#include "arithmeticAverage.hpp"
#include <iostream>
#include <memory>
#include <algorithm>
#include <math.h>
#include <numeric>

double ArithmeticAverage(std::vector<int>& v1, std::vector<int>& v2)
{
    double total = 0.0;
    int sizesum = v1.size() + v2.size();
    std::transform(v1.begin(), v1.end(), v2.begin(), v1.begin(), std::plus<int>());
    for(const auto x : v1) { total += x;}
    return total / sizesum;
}

double Distance(std::vector<int> v1, std::vector<int> v2)
{
     return std::sqrt(std::inner_product(v1.begin(), v1.end(), v2.begin(), 0,std::plus<>(), 
    [](auto x, auto y){return std::pow(y - x, 2); }));
}
