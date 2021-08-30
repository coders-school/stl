#include <iomanip>
#include <iostream>
#include "arithmeticAverage.hpp"

int main()
{
    std::vector<int> vec1{ 5, 8, 2, 13 };
    std::vector<int> vec2{ 15, 4, 2, -6 };

    std::cout << ArithmeticAverage(vec1, vec2) << std::endl;
    std::cout << std::setprecision(10) << Distance(vec1, vec2) << std::endl;

    return 0;
}
