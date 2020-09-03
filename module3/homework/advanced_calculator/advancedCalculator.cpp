#include "advancedCalculator.hpp"
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <regex>

bool isIntiger(double value) {
    return value - int(value) == 0;
}

double factorial(double value) {
    if(value <= 1){
        return 1;
    }

    double result = 1;
    for (double i = value; i > 1; --i) {
        result *= i;
    }
    return result;
}

std::map<std::string, std::function<double(double, double)>> operations{
    {"+", std::plus<double>()},
    {"-", std::minus<double>()},
    {"*", std::multiplies<double>()},
    {"/", std::divides<double>()},
    {"%", std::modulus<int>()},
    //{"!", [](double a1, double b1){return 2.5;}},
    {"^", [](double base, double nthPow) { return std::pow(base, nthPow); }},
    {"$", [](double base, double nthRoot) { return std::pow(base, 1.0 / nthRoot); }}};

bool badCharacter(std::string input) {
    const std::array<char, 8> calculationOperators{'+', '-', '*', '/', '%', '!', '^', '$'};

    return std::none_of(input.begin(), input.end(), [calculationOperators](char ch) {
        //std::any_of(calculationOperators.begin(), calculationOperators.end(), ch);
        for (auto el : calculationOperators) {
            if (el == ch) {
                return true;
            }
        }
        return false;
    });
}

ErrorCode process(std::string input, double* out) {
    if (badCharacter(input)) {
        return ErrorCode::BadCharacter;
    }

    std::cout << input << '\n';
    std::smatch matches;

    std::regex operationPattern(R"(([-]?\d+.\d+|[-]?\d+)\s?([+*/\-%!^$])\s?([-]?\d+.\d+|[-]?\d+))");
    std::regex factorialPattern(R"((\d+)\s?(\!))");

    if (std::regex_search(input, matches, operationPattern)) {
        std::cout << "Operations handling[" << matches[2] << "]\n";
        double val1 = std::stod(matches[1]);
        std::string operation = matches[2];
        double val2 = std::stod(matches[3]);

        if (operation == "/" && val2 == 0) {
            return ErrorCode::DivideBy0;
        } else if (operation == "$" && val1 <= 0) {
            return ErrorCode::SqrtOfNegativeNumber;
        } else if (operation == "%" && !isIntiger(val1) && !isIntiger(val2)) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }

        *out = operations.at(operation)(val1, val2);
        std::cout << *out << '\n';
        return ErrorCode::Ok;
    } else if (std::regex_search(input, matches, factorialPattern)) {
        std::cout << matches[0] << '\t' << matches[1] << '\t' << matches[2] << '\n';
        double value = std::stod(matches[1]);
        //factorial
        std::cout << "Factorial dealing[!] \n";
        *out = factorial(value);
        std::cout << *out << '\n';
        return ErrorCode::Ok;
    }

    return ErrorCode::BadFormat;
}
