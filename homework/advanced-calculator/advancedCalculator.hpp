#pragma once

#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

std::map<char, std::function<double(const double&, const double&)>>
    mapOfType = {
        {'+', [](const auto& a, const auto& b) -> double { return a + b; }},
        {'*', [](const auto& a, const auto& b) -> double { return a * b; }},
        {'/', [](const auto& a, const auto& b) -> double { return a / b; }},
        {'-', [](const auto& a, const auto& b) -> double { return a - b; }},
        {'%', [](const auto& a, const auto& b) -> double { return a % b; }},
        {'!', [](const auto& a, const auto& b) -> double { return std::tgamma(a + 1); }},
        {'^', [](const auto& a, const auto& b) -> double { return std::pow(a, b); }},
        {'$', [](const auto& a, const auto& b) -> double { return std::pow(a, 1.0 / b); }},
};

ErrorCode process(std::string input, double* out);