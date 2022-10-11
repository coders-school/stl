#include "advancedCalculator.hpp"

#include <algorithm>
#include <cmath>
#include <numbers>
#include <ranges>
#include <string>
#include <string_view>

namespace calculator {
    using std::numbers::pi_v;
    using std::pow;
    using std::sqrt;
    using std::abs;

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
            {'$', sqrtRoot}
    };
}

bool checkIfCharIsACommand(const char com) {
    return std::any_of(calculator::commands.cbegin(), calculator::commands.cend(), [com](auto c) {
        return com == c.first;
    });
}

bool checkIfInputDataGotBadCharacter(const std::string& inputData) {
    return std::any_of(inputData.cbegin(), inputData.cend(), [](char c) -> bool {
        return !isdigit(c) && !checkIfCharIsACommand(c) && c != ',' && c != '.';
    });
}

ErrorCode findFunction(const std::string& inputData, char& command) {
    if (checkIfInputDataGotBadCharacter(inputData)) {
        return ErrorCode::BadCharacter;
    }
    auto beginInputData = inputData.cbegin();
    if (inputData[0] == '-') {
        beginInputData++;
    }
    auto it = std::find_first_of(beginInputData, inputData.cend(),
                                 calculator::commands.cbegin(), calculator::commands.cend(),
                                 [](auto inputChar, auto commandChar) {
                                     return inputChar == commandChar.first;
                                 });
    auto itComma = std::find(beginInputData, inputData.cend(), ',');
    int countPluses = std::count(beginInputData, inputData.cend(), '+');
    if (it == inputData.cend() || it == inputData.cbegin() && *it != '-' || itComma != inputData.cend() ||
        *it == '+' && countPluses > 1 || *it != '+' && countPluses > 0 || *it == '!' && it + 1 != inputData.cend()) {
        return ErrorCode::BadFormat;
    }
    command = *it;
    return ErrorCode::OK;
}

ErrorCode checkIfFunctionHasBadCommand(const std::string& inputData, char command, double& lhs, double& rhs) {
    size_t distance = inputData.find_first_of(command);;
    if (inputData[0] == '-' && command == '-') {
        distance = inputData.find_first_of('-', 1);
    }
    std::string lValue = inputData.substr(0, distance);
    std::string rValue = inputData.substr(distance + 1, inputData.size());
    if (std::count(lValue.cbegin(), lValue.cend(), '.') > 1 || std::count(rValue.cbegin(), rValue.cend(), '.') > 1) {
        return ErrorCode::BadFormat;
    }
    try {
        lhs = std::stod(lValue);
        if (command != '!') {
            rhs = std::stod(rValue);
        }
    } catch (...) {
        return ErrorCode::BadFormat;
    }
    return ErrorCode::OK;
}

ErrorCode checkIfNumberCanBeUsedByCommand(char command, double lhs, double rhs) {
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

ErrorCode process(const std::string& inputData, double* result) {
    ErrorCode errorCode = ErrorCode::OK;
    char command = '\0';
    std::string inputDataWithoutSpaces = inputData;
    auto it = std::remove(inputDataWithoutSpaces.begin(), inputDataWithoutSpaces.end(), ' ');
    inputDataWithoutSpaces.erase(it, inputDataWithoutSpaces.end());
    double lhs = 0.0;
    double rhs = 0.0;
    errorCode = findFunction(inputDataWithoutSpaces, command);
    if (errorCode != ErrorCode::OK) {
        return errorCode;
    }
    errorCode = checkIfFunctionHasBadCommand(inputDataWithoutSpaces, command, lhs, rhs);
    if (errorCode != ErrorCode::OK) {
        return errorCode;
    }

    errorCode = checkIfNumberCanBeUsedByCommand(command, lhs, rhs);
    if (errorCode != ErrorCode::OK) {
        return errorCode;
    }

    *result = calculator::commands[command](lhs, rhs);
    return errorCode;
}
