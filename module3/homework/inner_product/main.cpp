#include <iostream>

#include "arithmeticAverage.hpp"

int main() {
    std::vector<int> vec1{1, 2, 3, 4};
    std::vector<int> vec2{1, 2, 3, 4};

    std::cout << ArithmeticAverage(vec1, vec2) << "\n";
    std::cout << Distance(vec1, vec2) << "\n";

    return 0;
}
