#include "advancedCalculator.hpp"

int main(void) {
    double result = 0;

    ErrorCode a;

    a = process("255 $ 3", &result);

    return 0;
}
