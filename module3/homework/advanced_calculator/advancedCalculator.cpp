#include "advancedCalculator.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <functional>
#include <iterator>
#include <map>

#include <iostream>

double factorial (double num) {
    if (num <= 0) 
        return 1;
    return std::tgamma(num + 1);
}

const std::map<char, std::function<double(double, double)>> equation {
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    {'%', std::modulus<int>()},
    {'^', [](double base, double exp) { return std::pow(base, exp); } },
    {'$', [](double base, double exp) { return std::pow(base, 1.0/exp); } }
};

ErrorCode process(std::string operation, double* out) {
    if (std::any_of(operation.cbegin(), operation.cend(), isalpha)) {
        return ErrorCode::BadCharacter;
    }
    const std::string forbiddenChar = "=[]@#&();?\\";
    for (const auto& it : forbiddenChar) {
        if (std::any_of(operation.cbegin(), operation.cend(), [&it](const char& c){ return it == c; } )) {
            return ErrorCode::BadCharacter;
        }
    }
    if (std::any_of(operation.cbegin(), operation.cend(), [](const char& c){ return c == ','; } )) {
        return ErrorCode::BadFormat;
    }
    operation.erase(remove_if(operation.begin(), operation.end(), isspace), operation.end());
    auto operandSeparator = std::find_if(operation.begin() + 1, operation.end(), [](const char& c){
        return (std::ispunct(c) && c != '.'); });
    if (std::count_if(operation.begin() + 1, operation.end(), [](const char& c){
        return (std::ispunct(c) && c != '.' && c != '-'); }) > 1) {
            return ErrorCode::BadFormat;
    }
    if (std::ispunct(operation[0]) && operation[0] != '-') {
        return ErrorCode::BadFormat;
    }
    if (std::count(operation.begin(), operation.end(), '.') > 2) {
        return ErrorCode::BadFormat;
    }
    std::string operandOne {};
    std::string operandTwo {};
    std::copy(operation.begin(), operandSeparator, std::back_inserter(operandOne));
    std::copy(operandSeparator + 1, operation.end(), std::back_inserter(operandTwo));
    if (*operandSeparator == '!' && std::isalnum(operandTwo[0])) {
        return ErrorCode::BadFormat;
    }
    if (*operandSeparator == '/' && std::stod(operandTwo) == 0) {
        return ErrorCode::DivideBy0;
    }
    if (*operandSeparator == '%' && (std::stod(operandTwo) == 0 || std::stoi(operandTwo) != std::stod(operandTwo))) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    if (*operandSeparator == '$' && (std::stod(operandOne) < 0 || std::stod(operandTwo) < 0)) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    if (*operandSeparator == '!') {
        *out = factorial(std::stod(operandOne));
        return ErrorCode::OK;
    }

    *out = equation.at(*operandSeparator)(std::stod(operandOne), std::stod(operandTwo));
    return ErrorCode::OK;
}