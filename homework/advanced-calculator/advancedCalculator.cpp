#include "advancedCalculator.hpp"

#include <algorithm>
#include <cmath>
#include <numbers>
#include <stdexcept>
#include <string>
#include <string_view>

namespace calculator {
using std::abs;
using std::pow;
using std::sqrt;

double addiction(const double lhs, const double rhs) {
    return lhs + rhs;
}

double multiply(const double lhs, const double rhs) {
    return lhs * rhs;
}

double divide(const double lhs, const double rhs) {
    return (lhs / rhs);
}

double substract(const double lhs, const double rhs) {
    return lhs - rhs;
}

double modulo(const double lhs, const double rhs) {
    return static_cast<int>(lhs) % static_cast<int>(rhs);
}

double factorial(double lhs, const double) {
    return std::tgamma(abs(lhs)) * lhs;
}

double power(const double lhs, const double rhs) {
    return pow(lhs, rhs);
}

double sqrtRoot(const double lhs, const double rhs) {
    return pow(lhs, 1.0 / rhs);
}

std::map<char, std::function<double(const double, const double)>> commands{
    {'+', addiction},
    {'*', multiply},
    {'/', divide},
    {'-', substract},
    {'%', modulo},
    {'!', factorial},
    {'^', power},
    {'$', sqrtRoot}};
}  // namespace calculator

bool checkIfCharIsACommand(const char com) {
    return std::any_of(calculator::commands.cbegin(), calculator::commands.cend(), [com](auto c) {
        return com == c.first;
    });
}

bool checkIfInputDataGotBadCharacter(const std::string& inputData) {
    return std::any_of(inputData.cbegin(), inputData.cend(), [](char c) {
        return !isdigit(c) && !checkIfCharIsACommand(c) && c != ',' && c != '.';
    });
}

bool isAComma(const std::string& inputData, auto& beginIterator) {
    return std::find(beginIterator, inputData.cend(), ',') != inputData.cend();
}

bool isTooMuchPluses(const std::string& inputdata, auto& beginIterator, char command) {
    int countPluses = static_cast<int>(std::count(beginIterator, inputdata.cend(), '+'));
    if (countPluses > 0 && command != '+' || countPluses > 1) {
        return true;
    }
    return false;
}

bool isFactiorialSingleNumber(const std::string& inputData, auto& commandIterator) {
    return *commandIterator == '!' && commandIterator + 1 != inputData.cend();
}

char findCommand(const std::string& inputData, auto& beginIterator) {
    auto commandIterator =
        std::find_first_of(beginIterator, inputData.cend(),
                           calculator::commands.cbegin(), calculator::commands.cend(),
                           [](auto inputChar, auto commandChar) {
                               return inputChar == commandChar.first;
                           });
    if (commandIterator == inputData.cend() || commandIterator == inputData.cbegin()) {
        return 0;
    }
    char command = *commandIterator;
    if (isFactiorialSingleNumber(inputData, commandIterator) ||
        isAComma(inputData, beginIterator) ||
        isTooMuchPluses(inputData, beginIterator, command)) {
        return 0;
    }

    return command;
}

ErrorCode findFunction(const std::string& inputData, char& command) {
    if (checkIfInputDataGotBadCharacter(inputData)) {
        return ErrorCode::BadCharacter;
    }

    auto beginInputData = inputData.cbegin();
    if (inputData[0] == '-') {
        beginInputData++;
    }

    command = findCommand(inputData, beginInputData);
    if (command == 0) {
        return ErrorCode::BadFormat;
    }

    return ErrorCode::OK;
}

bool isMoreThanOneDotInNumber(const std::string& number) {
    return std::count(number.cbegin(), number.cend(), '.') > 1;
}

bool trySplitInputDataToTwoStringOfNumbers(const std::string& inputData, char command, std::string& leftSide, std::string& rightSide) {
    size_t distance = inputData.find_first_of(command);
    if (inputData[0] == command) {
        distance = inputData.find_first_of('-', 1);
    }
    leftSide = inputData.substr(0, distance);
    rightSide = inputData.substr(distance + 1, inputData.size());
    if (isMoreThanOneDotInNumber(leftSide) || isMoreThanOneDotInNumber(rightSide)) {
        return false;
    }

    return true;
}

ErrorCode checkIfFunctionHasBadCommand(const std::string& inputData, char command, double& lhs, double& rhs) {
    std::string leftSideOfInputData;
    std::string rightSideOfInputData;
    if (!trySplitInputDataToTwoStringOfNumbers(inputData, command, leftSideOfInputData, rightSideOfInputData)) {
        return ErrorCode::BadFormat;
    }

    try {
        lhs = std::stod(leftSideOfInputData);
        if (command != '!') {
            rhs = std::stod(rightSideOfInputData);
        }
    } catch (std::invalid_argument&) {
        return ErrorCode::BadFormat;
    }
    return ErrorCode::OK;
}

ErrorCode checkIfNumbersCanBeUsedByCommand(char command, double lhs, double rhs) {
    if (command == '/' && rhs == 0) {
        return ErrorCode::DivideBy0;
    }
    if (command == '%' && (static_cast<int>(lhs) != lhs || static_cast<int>(rhs) != rhs)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    if (command == '$' && lhs < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    return ErrorCode::OK;
}

bool isErrorCodeDifferentThanOK(ErrorCode& errorCode, std::string inputData, char& command, double& lhs, double& rhs) {
    inputData.erase(std::remove(inputData.begin(), inputData.end(), ' '), inputData.end());

    errorCode = findFunction(inputData, command);
    if (errorCode != ErrorCode::OK) {
        return true;
    }

    errorCode = checkIfFunctionHasBadCommand(inputData, command, lhs, rhs);
    if (errorCode != ErrorCode::OK) {
        return true;
    }

    errorCode = checkIfNumbersCanBeUsedByCommand(command, lhs, rhs);
    if (errorCode != ErrorCode::OK) {
        return true;
    }
    return false;
}

ErrorCode process(const std::string& inputData, double* result) {
    ErrorCode errorCode = ErrorCode::OK;
    char command = '\0';
    double lhs = 0.0;
    double rhs = 0.0;
    if (isErrorCodeDifferentThanOK(errorCode, inputData, command, lhs, rhs)) {
        return errorCode;
    }
    *result = calculator::commands[command](lhs, rhs);
    return errorCode;
}
