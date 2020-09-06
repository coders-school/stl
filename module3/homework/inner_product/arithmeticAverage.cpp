#include "arithmeticAverage.hpp"

#include <cmath>
#include <functional>
#include <numeric>


float ArithmeticAverage::operator()(std::vector<int>& lhs, std::vector<int>& rhs) const
{
    const int initNum = 0;
    int fullSize = lhs.size() + rhs.size();
    auto sum = std::fabs(std::inner_product(lhs.begin(), lhs.end(), rhs.begin(), initNum, std::plus<>(), std::plus<>()));
    return std::divides{}(sum, fullSize);
}
