#include "arithmeticAverage.hpp"

#include <functional>
#include <numeric>

float ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second){

    return std::inner_product(first.cbegin(), first.cend(), second.cbegin(), 0,
                              std::plus<>(), std::plus<>()) /
                              (first.size() + second.size());
}