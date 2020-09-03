#include <iostream>

#include "advancedCalculator.hpp"

int main() {
    double a = 1;
    ErrorCode err = process("5+5", &a);
    ErrorCode err2 = process("3!", &a);
    ErrorCode err3 = process("15*2!", &a);
    ErrorCode err4 = process("15%2!", &a);
    std::cout <<factorial(5)<<'\n';
    return 0;
}
