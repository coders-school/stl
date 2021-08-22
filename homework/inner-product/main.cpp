#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

#include "arithmeticAverage.hpp"

int main()
{
    std::vector<int> vec1{ 7, 4, 3, 13 };
    std::vector<int> vec2{ 17, 6, 2, -2 };

    std::cout << ArithmeticAverage(vec1, vec2) << std::endl;
    std::cout << std::setprecision(10) << Distance(vec1, vec2) << std::endl;

    return 0;
}
