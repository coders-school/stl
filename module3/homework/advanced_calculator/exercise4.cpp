#include <string>
#include "advancedCalculator.hpp"

ErrorCode process(std::string input, double* out) {
    Calculator calc;
    return calc.process(input, out);
}
