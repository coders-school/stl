#include "advancedCalculator.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <functional>
#include <iterator>
#include <map>

#include <iostream>

double factorial (double num) {
    /*if (num <= 0) {
        return 1.0;
    }
    return std::tgamma(num);*/
    if (num <= 0) 
        return 1; 
    return num * factorial(num - 1); 
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
    char sign = *operandSeparator;
    std::copy(operation.begin(), operandSeparator, std::back_inserter(operandOne));
    std::copy(operandSeparator + 1, operation.end(), std::back_inserter(operandTwo));
    double operand1 = std::stod(operandOne);
    double operand2 = std::stod(operandTwo);
    if (sign == '!' && std::isalnum(operandTwo[0])) {
        return ErrorCode::BadFormat;
    }
    if (sign == '/' && operand2 == 0) {
        return ErrorCode::DivideBy0;
    }
    if (sign == '%' && (operand2 == 0 || std::stoi(operandTwo) != std::stod(operandTwo))) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    if (sign == '$' && (operand1 < 0 || operand2 < 0)) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    if (sign == '!') {
        *out = factorial(operand1);
        return ErrorCode::OK;
    }

    *out = equation.at(sign)(operand1, operand2);
    return ErrorCode::OK;
}