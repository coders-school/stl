#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <regex>
#include <string>
#include "advancedCalculator.hpp"

bool isInteger(double number) {
    return number == floor(number);
}

bool isAcceptableOperation(char operation) {
    const std::string acceptableOperations{"+-*/%!^$"};
    auto it = std::find_if(acceptableOperations.begin(), acceptableOperations.end(), [operation](auto el) { return el == operation; });

    return it != acceptableOperations.end();
}

ErrorCode process(std::string input, double* out) {
    char operation{};
    double firstNumber{}, secondNumber{2};
    ErrorCode returnCode{ErrorCode::OK};

    const std::regex badFormatRegex("^(-?[0-9]+\\.?([0-9]+)?)(?:(?=!)(!)|(?!!)([\\+\\-\\*\\/\\^\\$%!#@&?\\[\\]]?(\\\\)?)(-?[0-9]+\\.?([0-9]+)?))$");
    std::smatch cleanedInput;

    input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());

    std::regex_search(input, cleanedInput, badFormatRegex);

    operation = *cleanedInput[4].str().c_str();

    //TODO cleanup, possibly encapsulate
    if (!cleanedInput.size()) {
        returnCode = ErrorCode::BadFormat;
    } else if (!isAcceptableOperation(operation) || '\\' == cleanedInput[5]) {
        if ('!' != cleanedInput[3]) {
            returnCode = ErrorCode::BadCharacter;
        }
    } else if ('/' == operation && 0 == std::stod(cleanedInput[6].str())) {
        returnCode = ErrorCode::DivideBy0;
    } else if ('%' == operation) {
        auto moduloNumber = std::stod(cleanedInput[6].str());
        if (!isInteger(moduloNumber) || 0 == moduloNumber) {
            returnCode = ErrorCode::ModuleOfNonIntegerValue;
        }
    } else if ('$' == operation && 0 > std::stod(cleanedInput[1].str())) {
        returnCode = ErrorCode::SqrtOfNegativeNumber;
    }

    if (ErrorCode::OK == returnCode && '!' != cleanedInput[3]) {
        firstNumber = std::stod(cleanedInput[1].str());
        secondNumber = std::stod(cleanedInput[6].str());
        *out = Calculator::calculate(operation, firstNumber, secondNumber);
    } else if (ErrorCode::OK == returnCode) {
        operation = '!';
        firstNumber = std::stod(cleanedInput[1].str());
        *out = Calculator::calculate(operation, firstNumber);
    }
    return returnCode;
}
