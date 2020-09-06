#include <iostream>
#include "arithmeticAverage.hpp"


int main() {
    std::vector<int> vec1{7, 4, 3};
    std::vector<int> vec2{17, 6, 2};

    std::cout << ArithmeticAverage(vec1, vec2) << '\n';
    std::cout << Distance(vec1, vec2) << '\n';

    return 0;
}
