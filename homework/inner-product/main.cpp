#include <iostream>
#include "arithmeticAverage.hpp"


int main() {
    // Testing ArithmeticAverage function
    // std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    // std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};
    // std::cout << ArithmeticAverage(first, second) << '\n';
    // Testing Distance function
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};
    double expected = 10.247;
    std::cout << Distance(first, second) << '\n';


}