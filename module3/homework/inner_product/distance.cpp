#include "distance.hpp"

#include <cmath>
#include <iostream>
#include <functional>
#include <numeric>

float Distance::operator()(std::vector<int>& lhs, std::vector<int>& rhs) const
{
    const int initNum = 0;
    const auto sum = std::inner_product(lhs.cbegin(), lhs.cend(), rhs.cbegin(), initNum,
                                            std::plus<>(), 
                                            [](int num1, int num2){
                                                float result = std::pow(num1 - num2, 2);
                                                return result;
                                            });
    std::cout << sum << " <- sum\n";                                        
    return std::sqrt(sum);
}
