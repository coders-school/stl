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
    if (isDigitAfterUnaryOperator(input)) {
        return true;
    }
    if (moreThanOneOperator(input)) {
        return true;
    }
    if (isWrongDivisionSign(input)) {
        return true;
    }
    return false;
}

bool noDigitBeforeOperator(const std::string& input) {
    std::regex pattern(R"((\d+)(\s+)?(\+|\-|\/|\*|\^|\$|\!|\%))");
    return !std::regex_search(input, pattern);
}

bool noDigitAfterBinaryOperator(const std::string& input) {
    std::regex pattern(R"(((\+|\-|\/|\*|\^|\$|\%)(\s+)?(\d+))?(\d+)(\s+)?(\!))");
    return !std::regex_search(input, pattern);
}

bool isDigitAfterUnaryOperator(const std::string& input) {
    std::regex pattern(R"((\!)(\s+)?(\d+))");
    return std::regex_search(input, pattern);
}

bool moreThanOneOperator(const std::string& input) {
    std::regex operators(R"((\+|\-|\/|\*|\^|\$|\%|\!))");
    std::smatch foundOperators;
    auto operators_begin = std::sregex_iterator(input.begin(), input.end(), operators);
    auto operators_end = std::sregex_iterator();
    auto equalToMinus = [](auto elem) { return elem.str() == "-"; };
    if (std::distance(operators_begin, operators_end) > 3) {
        return true;
    }
    if (std::distance(operators_begin, operators_end) == 3) {
        return !std::all_of(operators_begin, operators_end, equalToMinus);
    }
    if (std::distance(operators_begin, operators_end) == 2) {
        if (!firstDigitIsNegative(input)) {
            return true;
        }
    }
    return false;
}

bool isWrongDivisionSign(const std::string& input) {
    std::regex pattern(R"((\.\S+\.)|(,))");
    return std::regex_search(input, pattern);
}

bool firstDigitIsNegative(const std::string& input) {
    std::regex pattern(R"(^(\s+)?(\-)(\s+)?(\d+))");
    return std::regex_search(input, pattern);
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
    std::cout << "badCharacter: " << isBadCharacter(input) << '\n';
    std::cout << "badFormat: " << isBadFormat(input) << '\n';

    return ErrorCode::OK;
}
