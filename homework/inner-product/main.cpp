#include <iostream>
#include "arithmeticAverage.hpp"

int main() {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    std::cout << ArithmeticAverage(first, second) << std::endl;

    std::vector<int> firstD{7, 4, 3, 13};
    std::vector<int> secondD{17, 6, 2, -2};
    std::cout << Distance(firstD, secondD) << std::endl;
}
