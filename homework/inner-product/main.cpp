#include <iostream>
#include <vector>
#include "arithmeticAverage.hpp"

int main() {
    std::vector<int> va{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> vb{3, 5, -2, 6, 7, -3, 6, 9};
    std::cout << ArithmeticAverage(va, vb);
    std::cout << "\n";
}