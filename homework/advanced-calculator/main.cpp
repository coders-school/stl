#include "advancedCalculator.hpp"

#include <iostream>

int main()
{
    double result = 0;
    std::cout << process("28.43 +-810.43", &result) << '\n';
    std::cout << process("5+5", &result) << '\n';

    return 0;
}