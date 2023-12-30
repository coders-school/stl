#include "arithmeticAverage.hpp"

#include <iostream>

int main() {
    std::vector<int> first{1, 2, 3, 4};
    std::vector<int> second{1, 2, 3, 4};
    std::cout << "Średnia: " << ArithmeticAverage(first, second) << "\n";
    return 0;
}
