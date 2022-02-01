#include <iostream>

#include "arithmeticAverage.hpp"

int main()
{
    std::vector v1 { 1, 2, 3, 4 };
    std::cout << "Aritmethic avarage of two vectors: `{1, 2, 3, 4}` `{1, 2, 3, 4}` = "
              << ArithmeticAverage(v1, v1) << std::endl;

    std::vector<int> first { -5, 4, 2, -5, 2, 4, 6, 7 };
    std::vector<int> second { 3, 5, -2, 6, 7, -3, 6, 9 };
    std::cout << "Aritmethic avarage of two vectors: "
              << "{ -5, 4, 2, -5, 2, 4, 6, 7 } and "
              << "{3, 5, -2, 6, 7, -3, 6, 9} = "
              << ArithmeticAverage(first, second) << std::endl;

    return 0;
}
