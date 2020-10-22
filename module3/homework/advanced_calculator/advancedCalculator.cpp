#include "advancedCalculator.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <regex>

auto addAction = [](double firstNumber, double secondNumber) {
    return firstNumber + secondNumber;
};

auto substractAction = [](double firstNumber, double secondNumber) {
    return firstNumber - secondNumber;
};

auto divideAction = [](double firstNumber, double secondNumber) {
    return firstNumber / secondNumber;
};

auto multiplyAction = [](double firstNumber, double secondNumber) {
    return firstNumber * secondNumber;
};

auto moduloAction = [](double firstNumber, double secondNumber) {
    return (int)firstNumber % (int)secondNumber;
};

auto sqrtAction = [](double firstNumber, double secondNumber) {
    return std::pow(firstNumber, 1 / secondNumber);
};

auto powerAction = [](double firstNumber, double secondNumber) {
    return std::pow(firstNumber, secondNumber);
};

auto factorialAction = [](double firstNumber, double secondNumber) {
    return std::tgamma(firstNumber + 1);
};

std::string eraseSpaces(std::string input)
{
    input.erase(std::remove_if(input.begin(),
                               input.end(),
                               [](unsigned char x) { return std::isspace(x); }),
                input.end());

    return input;
}

ErrorCode allowedCharacters(std::string input)
{
    const std::string ALLOWEDCHARACTERS = "+*/-%!^$1234567890.,";

    auto foundBadCharacter = input.find_first_not_of(ALLOWEDCHARACTERS);
    if (foundBadCharacter != std::string::npos) {
        return ErrorCode::BadCharacter;
    }

    if (input.find(',') != std::string::npos) {
        return ErrorCode::BadFormat;
    }

    return ErrorCode::OK;
}

ErrorCode allowedFormat(std::string input)
{
    const std::regex patternUnary("(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))(!)");
    const std::regex patternBinary("(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))([-/+/*///^%/$])(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))");

    std::smatch singleMatch;

    if (!std::regex_match(input, singleMatch, patternUnary) && !std::regex_match(input, singleMatch, patternBinary)) {
        return ErrorCode::BadFormat;
    }
    return ErrorCode::OK;
}

std::vector<std::string> unpackExpression(std::string input)
{
    const std::regex patternUnary("(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))(!)");
    const std::regex patternBinary("(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))([-/+/*///^%!/$])(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))");

    std::smatch singleMatch;

    std::string firstNumber{};
    std::string action{};
    std::string secondNumber{};

    if (std::regex_match(input, singleMatch, patternUnary)) {
        firstNumber = singleMatch[1];
        action = singleMatch[4];
        secondNumber = "0";
    }

    if (std::regex_match(input, singleMatch, patternBinary)) {
        firstNumber = singleMatch[1];
        action = singleMatch[4];
        secondNumber = singleMatch[5];
    }

    return {{firstNumber}, {action}, {secondNumber}};
}

ErrorCode prohibitedOperations(std::vector<std::string> unpackedElements)
{
    const double firstNumber = std::stod(unpackedElements[0]);
    const std::string action = unpackedElements[1];
    const double secondNumber = std::stod(unpackedElements[2]);

    if ((action == "/") && (!secondNumber)) {
        return ErrorCode::DivideBy0;
    }

    if (action == "%") {
        if (firstNumber > 0 || secondNumber > 0) {
            if ((firstNumber - int(firstNumber) > 0) || (secondNumber - int(secondNumber) > 0)) {
                return ErrorCode::ModuleOfNonIntegerValue;
            }
        }

        if (firstNumber < 0 || secondNumber < 0) {
            if ((firstNumber - int(firstNumber) < 0) || (secondNumber - int(secondNumber) < 0)) {
                return ErrorCode::ModuleOfNonIntegerValue;
            }
        }
    }

    if ((action == "$") && (firstNumber < 0)) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    return ErrorCode::OK;
}

double calculate(specMap actionsHolder, std::vector<std::string> unpackedElements)
{
    double firstNumber = std::stod(unpackedElements[0]);
    const char* action = unpackedElements[1].c_str();
    double secondNumber = std::stod(unpackedElements[2]);

    specMap::iterator it = actionsHolder.find(*action);
    auto result = it->second(firstNumber, secondNumber);

    return result;
}

ErrorCode process(std::string input, double* out)
{
    specMap actionsHolder{
        {'+', addAction},
        {'-', substractAction},
        {'/', divideAction},
        {'*', multiplyAction},
        {'%', moduloAction},
        {'^', powerAction},
        {'$', sqrtAction},
        {'!', factorialAction}};

    ErrorCode errorCode{ErrorCode::OK};
    std::vector<std::string> unpackedElements{};

    input = eraseSpaces(input);
    errorCode = allowedCharacters(input);
    if (errorCode == ErrorCode::OK) {
        errorCode = allowedFormat(input);
    }
    if (errorCode == ErrorCode::OK) {
        unpackedElements = unpackExpression(input);
        errorCode = prohibitedOperations(unpackedElements);
    };
    if (errorCode == ErrorCode::OK) {
        *out = calculate(actionsHolder, unpackedElements);
    }

    return errorCode;
}
