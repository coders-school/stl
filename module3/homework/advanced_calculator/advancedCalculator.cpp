#include "advancedCalculator.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <regex>

void printInfo() {
    std::cout << "Possible operations: {'+', '-', '*', '/', '%', '!', '$', '^'}\n";
    std::cout << "Eg. >>> 5 + 5\n10\n";
    std::cout << "To quit type 'q'\n";
}

double factorial(double n) {
    return (n > 0.0) ? tgamma(n + 1) : 1.0;
}

bool isInteger(double n) {
    return (n == static_cast<int>(n));
}

bool badChar(const std::string& input) {
    const std::string allowed_ops{"+-*/!$%^.,"};

    auto pred = [&allowed_ops](const auto el){
        return (!isdigit(el) && std::find(allowed_ops.cbegin(), allowed_ops.cend(), el) == allowed_ops.cend());
    };

    return std::any_of(input.cbegin(), input.cend(), pred);
}

std::map<char, std::function<double(double, double)>> operators{
    {'+', [](const auto lhs, const auto rhs) { return lhs + rhs; }},
    {'-', [](const auto lhs, const auto rhs) { return lhs - rhs; }},
    {'*', [](const auto lhs, const auto rhs) { return lhs * rhs; }},
    {'/', [](const auto lhs, const auto rhs) { return lhs / rhs; }},
    {'%', [](const auto lhs, const auto rhs) { return static_cast<int>(lhs) % static_cast<int>(rhs); }},
    {'^', [](const auto lhs, const auto rhs) { return pow(lhs, rhs); }},
    {'$', [](const auto lhs, const auto rhs) { return pow(lhs, 1.0 / rhs); }},
    {'!', [](const auto lhs, const auto rhs) { return factorial(lhs); }}};

std::vector<std::string> getEquation(const std::string& input) {
    const std::regex pattern("(-?[0-9]+\\.?[0-9]*)([^!{1}])(-?[0-9]+\\.?[0-9]*)");
    const std::regex pattern_factorial("(-?[0-9]+\\.?[0-9]*)(!{1})");
    std::smatch match;
    std::vector<std::string> result;

    if (std::regex_match(input, match, pattern)) {
        result.push_back(match[1]);
        result.push_back(match[2]);
        result.push_back(match[3]);
    } else if (std::regex_match(input, match, pattern_factorial)) {
        result.push_back(match[1]);
        result.push_back(match[2]);
    }

    return (result.size() >= 2) ? result : std::vector<std::string>();
}

ErrorCode validation(double num1, double num2, char op) {
    switch (op) {
    case '/':
        return (num2 == 0.0) ? ErrorCode::DivideBy0 : ErrorCode::OK;
    case '%':
        return (!isInteger(num1) || !isInteger(num2)) ? ErrorCode::ModuleOfNonIntegerValue : ErrorCode::OK;
    case '$':
        return (num1 < 0) ? ErrorCode::SqrtOfNegativeNumber : ErrorCode::OK;
    default:
        return ErrorCode::OK;
    }
}

ErrorCode process(std::string input, double* out) {
    input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());

    if (badChar(input)) {
        return ErrorCode::BadCharacter;
    }

    std::vector<std::string> data = getEquation(input);
    if (data.size() == 0) {
        return ErrorCode::BadFormat;
    }

    double num1 = std::stod(data[0]);
    double num2{};
    char op = data[1][0];
    if (op != '!') {
        num2 = std::stod(data[2]);
    }

    auto ec = validation(num1, num2, op);
    if (ec == ErrorCode::OK) {
        *out = operators[op](num1, num2);
        return ec;
    }

    return ec;
}

std::string getErrorMsg(ErrorCode ec) {
    switch (ec) {
    case ErrorCode::BadCharacter:
        return "Invalid character.";
    case ErrorCode::BadFormat:
        return "Invalid format.";
    case ErrorCode::DivideBy0:
        return "Division by 0 is forbidden.";
    case ErrorCode::ModuleOfNonIntegerValue:
        return "Modulo applies only for integers.";
    case ErrorCode::SqrtOfNegativeNumber:
        return "Complex numbers are not supported.";
    default:
        return "Something went wrong...";
    }
}
