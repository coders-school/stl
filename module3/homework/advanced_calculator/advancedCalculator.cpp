#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <variant>

bool isBadCharacter(const std::string& input) {
    std::string badCharacters{R"([^0-9\+\-\*\/\^\%\!\$\s])"};
    std::regex pattern(badCharacters);
    return std::regex_search(input, pattern);
}

bool isBadFormat(const std::string& input) {
    if (noDigitBeforeOperator(input)) {
        return true;
    }
    if (noDigitAfterBinaryOperator(input)) {
        return true;
    }
    return false;
}

bool noDigitBeforeOperator(const std::string& input) {
    std::regex pattern(R"(\d+)(\s+)(\+|\-|\/|\*|\^|\$|\!|\%)");
    return !std::regex_search(input, pattern);
}

bool noDigitAfterBinaryOperator(const std::string& input) {
    std::regex pattern(R"(\+|\-|\/|\*|\^|\$|\%)(\s+)(\d+)");
    return !std::regex_search(input, pattern);
}


ErrorCode process(std::string input, double* out) {
    std::variant<std::function<double(double, double)>, std::function<int(int, int)>, std::function<double(double)>>
        functions;
    std::map<char, decltype(functions)> basicMathOperations{
        {'+', std::function<double(double, double)>([](double lhs, double rhs) { return lhs + rhs; })},
        {'-', std::function<double(double, double)>([](double lhs, double rhs) { return lhs - rhs; })},
        {'*', std::function<double(double, double)>([](double lhs, double rhs) { return lhs * rhs; })},
        {'/', std::function<double(double, double)>([](double lhs, double rhs) { return lhs / rhs; })},
        {'%', std::function<int(int, int)>([](int lhs, int rhs) { return lhs % rhs; })},
        {'!', std::function<double(double)>([](double lhs) { return std::tgamma(lhs + 1); })},
        {'^', std::function<double(double, double)>([](double lhs, double rhs) { return std::pow(lhs, rhs); })},
        {'$', std::function<double(double, double)>([](double lhs, double rhs) { return std::pow(lhs, 1 / rhs); })}};

    return ErrorCode::OK;
}
