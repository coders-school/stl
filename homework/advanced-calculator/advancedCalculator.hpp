#pragma once

#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <iterator>
#include <map>
#include <regex>
#include <string>

enum ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

const std::map<char, std::function<double(double, double)>> operationLambdaMap{
    {'+', [](double x, double y) { return x + y; }},
    {'-', [](double x, double y) { return x - y; }},
    {'*', [](double x, double y) { return x * y; }},
    {'/', [](double x, double y) { return x / y; }},
    {'%', [](double x, double y) { return (int)x % (int)y; }},
    {'^', [](double x, double y) { return std::pow(x, y); }},
    {'$', [](double x, double y) { return std::pow(x, 1 / y); }},
    {'!', [](double n, double dummy = 0) {int k = 1; if (n < 0) k = -1; return k * std::tgamma(std::abs(n) + 1); }}};

ErrorCode process(std::string input, double* out);