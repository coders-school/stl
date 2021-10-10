#include <iostream>
#include "arithmeticAverage.hpp"

int main()
{

    // std::vector<int> x{1, 2, 3, 4};
    // std::vector<int> y{1, 2, 3, 4};
    std::vector<int> x{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> y{3, 5, -2, 6, 7, -3, 6, 9};

    std::cout << ArithmeticAverage(x, y) << '\n';

    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    std::cout << Distance(first, second); //10.247;
    return 0;
}