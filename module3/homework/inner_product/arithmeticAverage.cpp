#include "arithmeticAverage.hpp"
#include <numeric>
#include <math.h>

double ArithmeticAverage(vecOfInt v1, vecOfInt v2){
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0,
                              std::plus<int>(), std::plus<int>()) / static_cast<double>((v1.size() * 2));
}

double Distance(vecOfInt v1, vecOfInt v2){
    return std::sqrt(std::inner_product(v1.begin(), v1.end(), v2.begin(), 0,
                                        std::plus<int>(),
                                                [](auto a, auto b)
                                                { return std::pow(b - a, 2); }));
}