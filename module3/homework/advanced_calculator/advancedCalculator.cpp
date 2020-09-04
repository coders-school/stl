#include "advancedCalculator.hpp"

#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <regex>

bool isIntiger(double value) {
    return std::abs(value) - std::abs(static_cast<int>(value)) == 0;
}

double factorial(double value) {
    if (value <= 1) {
        return 1;
    }
    return std::tgamma(value + 1);
}

const std::map<std::string, std::function<double(double, double)>> operations{
    {"+", std::plus<double>()},
    {"-", std::minus<double>()},
    {"*", std::multiplies<double>()},
    {"/", std::divides<double>()},
    {"%", std::modulus<int>()},
    {"^", [](double base, double nthPow) { return std::pow(base, nthPow); }},
    {"$", [](double base, double nthRoot) { return std::pow(base, 1.0 / nthRoot); }}};

bool badCharacter(std::string input) {
    const std::array<char, 10> calculationOperators{'+', '-', '*', '/', '%', '!', '^', '$', '.', ','};

    return std::any_of(input.begin(), input.end(), [calculationOperators](char ch) {
        return std::isalpha(ch) || (std::ispunct(ch) && (std::find(calculationOperators.begin(), calculationOperators.end(), ch) == calculationOperators.end()));
    });
}

ErrorCode process(std::string input, double* out) {
    if (badCharacter(input)) {
        return ErrorCode::BadCharacter;
    }

    if (std::find(input.begin(), input.end(), ',') != input.end()) {
        return ErrorCode::BadFormat;
    }

    std::smatch matches;

    std::regex operationPattern(R"(([-]?\d+\.\d+|[-]?\d+)\s?([+*/\-%^$])\s?([-]?\d+\.\d+|[-]?\d+))");
    std::regex factorialPattern(R"(([-]?\d+\.\d+|[-]?\d+)\s?(\!))");

    if (std::regex_search(input, matches, operationPattern)) {
        if (matches[0] != input) {
            return ErrorCode::BadFormat;
        }
        double val1 = std::stod(matches[1]);
        double val2 = std::stod(matches[3]);
        std::string operation = matches[2];

        if (operation == "/" && val2 == 0) {
            return ErrorCode::DivideBy0;
        } else if (operation == "$" && (val1 < 0)) {
            return ErrorCode::SqrtOfNegativeNumber;
        } else if (operation == "%" && (!isIntiger(val1) || !isIntiger(val2))) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }

        *out = operations.at(operation)(val1, val2);
        return ErrorCode::OK;
    } else if (std::regex_search(input, matches, factorialPattern)) {
        if (matches[0] != input) {
            return ErrorCode::BadFormat;
        }

        double value = std::stod(matches[1]);
        *out = factorial(value);
        return ErrorCode::OK;
    }

    return ErrorCode::BadFormat;
}
