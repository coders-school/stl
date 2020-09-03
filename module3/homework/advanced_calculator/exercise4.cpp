#include <string>
#include "advancedCalculator.hpp"

ErrorCode process(std::string input, double* out) {
    char operation{};
    double firstNumber{}, secondNumber{};
    ErrorCode returnCode{ErrorCode::OK};

    *out = Calculator::calculate(operation, firstNumber, secondNumber);
    return returnCode;
}
