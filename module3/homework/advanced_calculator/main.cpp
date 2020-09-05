#include "advancedCalculator.hpp"

int main(void) {
    double result = 0;

    ErrorCode a;

    a = process("123.4 ! 345", &result);

    return 0;
}
