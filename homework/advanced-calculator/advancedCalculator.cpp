#include "advancedCalculator.hpp"
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <string>

MapContainer operations{
    {'+', [](const double& a, const double& b) { return a + b; }},
    {'-', [](const double& a, const double& b) { return a - b; }},
    {'*', [](const double& a, const double& b) { return a * b; }},
    {'/', [](const double& a, const double& b) { return a / b; }},
    {'%', moduloOperation},
    {'!', factorialOperation},
    {'^', [](const double& a, const double& b) { return std::pow(a, b); }},
    {'$', [](const double& a, const double& b) { return std::pow(a, 1 / b); }},
};

constexpr std::array<char, 1> separators{'.'};

double moduloOperation(const double& a, const double& b) {
    return static_cast<int>(a) % static_cast<int>(b);
}

double factorialOperation(const double& a, const double& b) {
    if (a < 0) {
        return std::tgamma((-a) + 1) * (-1);
    }
    return std::tgamma(a + 1);
}

ErrorCode process(std::string input, double* out) {
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    double a{0.0};
    double b{0.0};
    char operationSign{' '};
    ErrorCode err{validateOperation(input, a, b, operationSign)};
    if (err == ErrorCode::OK) {
        *out = operations.at(operationSign)(a, b);
    }
    return err;
}

ErrorCode validateOperation(const std::string& input, double& a, double& b, char& operationSign) {
    auto it = input.cbegin();
    ErrorCode err;
    std::string firstArg;
    err = parseValue(input, firstArg, it);
    if (err != ErrorCode::OK) {
        return err;
    }
    operationSign = parseOperator(it);
    std::string secondArg;
    err = parseValue(input, secondArg, it);
    if (err != ErrorCode::OK) {
        return err;
    }

    // In case of valid operation at the end like "2 + 2 +"
    std::string checkSum{firstArg + operationSign + secondArg};
    if (checkSum != input) {
        return ErrorCode::BadFormat;
    }
    if (operationSign == '%') {
        for (const auto separator : separators) {
            if (firstArg.find(separator) != std::string::npos || secondArg.find(separator) != std::string::npos) {
                return ErrorCode::ModuleOfNonIntegerValue;
            }
        }
    }
    if (firstArg.empty()) {
        return ErrorCode::BadFormat;
    }
    a = std::stod(firstArg);
    if (operationSign != '!') {
        if (secondArg.empty()) {
            return ErrorCode::BadFormat;
        }
        b = std::stod(secondArg);
    } else {
        if (!secondArg.empty()) {
            return ErrorCode::BadFormat;
        }
        b = 0;
    }
    if (operationSign == '/' && b == 0) {
        return ErrorCode::DivideBy0;
    }
    if (operationSign == '$' && a < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    return ErrorCode::OK;
}

ErrorCode parseValue(const std::string& input, std::string& output, std::string::const_iterator& it) {
    bool separatorAllowed{true};
    ErrorCode err{ErrorCode::OK};
    auto first = it;
    if (*it == '-') {
        ++it;
    }
    for (; it != input.cend(); ++it) {
        if (std::find(separators.cbegin(), separators.cend(), *it) != separators.cend() && separatorAllowed) {
            separatorAllowed = false;
            continue;
        }
        if (std::find(separators.cbegin(), separators.cend(), *it) != separators.cend() && !separatorAllowed) {
            err = ErrorCode::BadFormat;
            continue;
        }
        if (std::isdigit(*it)) {
            continue;
        }
        if (*it == ',') {
            err = ErrorCode::BadFormat;
            continue;
        }
        // Intention: This checks char after valid value (if part of the string) if it is a valid operation
        if (operations.find(*it) != operations.end()) {
            break;
        }
        return ErrorCode::BadCharacter;
    }
    output = std::string(first, it);
    return err;
}

char parseOperator(std::string::const_iterator& it) {
    auto result = *it;
    ++it;
    return result;
}
