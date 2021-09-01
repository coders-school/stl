#include "arithmeticAverage.hpp"
#include <iostream>


int main () {
    std::vector<int> first{7, 4, 3};
    std::vector<int> second{17, 6, 2};

    ArithmeticAverage(first, second);
    Distance(first, second);

    return 0;
}