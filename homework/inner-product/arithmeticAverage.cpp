

#include "arithmeticAverage.hpp"
#include <iostream>
#include <memory>
#include <algorithm>
#include <math.h>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& v1, const std::vector<int>& v2)
{
 double total = std::accumulate(v1.begin(), v1.end(),0) + std::accumulate(v2.begin(), v2.end(),0);
    return  total / (v1.size() + v2.size());
  
}

double Distance(const std::vector<int>& v1, const std::vector<int>& v2)
{
     return std::sqrt(std::inner_product(v1.begin(), v1.end(), v2.begin(), 0,std::plus<>(), 
    [](auto x, auto y){return std::pow(y - x, 2); }));
}