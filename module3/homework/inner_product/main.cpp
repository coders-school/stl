#include <iostream>
#include <vector>

#include "arithmeticAverage.hpp"

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {2, 3, 4, 5};
    double result;
    result = ArithmeticAverage(a, b);
    std::cout << result << std::endl;

    result = Distance(a, b);
    std::cout << result << std::endl;
    return 0;
}
