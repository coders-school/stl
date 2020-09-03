#include <iostream>

#include "advancedCalculator.hpp"

int main() {
    double a = 1;
    ErrorCode err = process("5+5", &a);
    ErrorCode err2 = process("1!", &a);


    return 0;
}
