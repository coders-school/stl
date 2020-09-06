#include "advancedCalculator.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <regex>
#include <string>

void compute(std::string& input) {
    double out = 0;
    auto err = process(input, &out);

    if (err == ErrorCode::OK) {
        std::cout << "result = " << out << '\n';
    } else {
        std::cout << errorCodeString.at(err) << '\n';
    }
}

bool isBadCharacter(std::string& input) {
    auto isBadChar = [](const char c) { return !std::isdigit(c) && !std::isspace(c) && c != '.' &&
                                               c != '!' && operations.find(c) == operations.end(); };
    return std::any_of(input.begin(), input.end(), isBadChar);
}

ErrorCode process(std::string input, double* out) {
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }

    std::smatch matches;
    auto operationType = GetOperationType(input, matches);

    switch (operationType) {
    case OperationType::Factorial:
        return computeFactorialExpression(matches, out);
    case OperationType::TwoArguments:
        return computeTwoArgumentsExpression(matches, out, input);
    default:
        return ErrorCode::BadFormat;
    }
}

OperationType GetOperationType(const std::string& input, std::smatch& matches) {
    std::regex operationPattern(Pattern::expression);
    std::regex factorialPattern(Pattern::factiorial);
    OperationType operationType = OperationType::Bad;

    std::regex_search(input, matches, operationPattern);
    if (matches.size() != 4) {
        if (std::regex_search(input, matches, factorialPattern)) {
            if (matches[0] == input) {
                operationType = OperationType::Factorial;
            }
        }
    } else {
        operationType = OperationType::TwoArguments;
    }

    return operationType;
}

ErrorCode computeFactorialExpression(std::smatch& matches, double* out) {
    std::string valueStr(matches[0]);
    valueStr.pop_back();
    double value = std::stod(valueStr);

    if (value <= 1.0) {
        *out = 1.0;
    } else {
        *out = std::tgamma(value + 1);
    }

    return ErrorCode::OK;
}

ErrorCode computeTwoArgumentsExpression(std::smatch& matches, double* out, std::string& input) {
    double firstVal = std::stod(matches[1]);
    std::string action = matches[2];
    double secondVal = std::stod(matches[3]);

    if (matches[0] != input) {
        return ErrorCode::BadFormat;
    } else if (action[0] == '/' && secondVal == 0.0) {
        return ErrorCode::DivideBy0;
    } else if (action[0] == '$' && firstVal < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    } else if (action[0] == '%' && (!isInteger(firstVal) || !isInteger(secondVal))) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    *out = operations.find(action[0])->second(firstVal, secondVal);
    return ErrorCode::OK;
}

bool isInteger(double& val) {
    return (std::fmod(val, 1) == 0);
}
