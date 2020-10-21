#include "arithmeticAverage.hpp"

#include <cmath>
#include <functional>
#include <numeric>


float ArithmeticAverage::operator()(std::vector<int>& lhs, std::vector<int>& rhs) const
{
    const int initNum = 0;
    int fullSize = lhs.size() + rhs.size();
    const auto sum = std::fabs(std::inner_product(lhs.cbegin(), lhs.cend(), rhs.cbegin(), initNum, std::plus<>(), std::plus<>()));
    return sum / fullSize;
}
