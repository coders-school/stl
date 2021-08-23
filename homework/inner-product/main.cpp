#include "arithmeticAverage.hpp"
#include <iostream>

int main() {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    std::cout << ArithmeticAverage(first, second);
    first = {7, 4, 3};
    second = {17, 6, 2};
    std::cout << Distance(first, second);
    first = {7, 4, 3, 13};
    second = {17, 6, 2, -2};
    std::cout << Distance(first, second);
    first = {7, 4, 3, 13};
    second = {17, 6, 2,};
    std::cout << Distance(first, second);
    return 0;
}