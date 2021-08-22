#pragma once
#include <map>
#include <cmath>
#include <functional>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

static std::map<char, std::function<ErrorCode(double first, double second, double* out)>> calculator_functions = {
    {'+', [](double first, double second, auto* out ) { *out = first + second; return ErrorCode::OK; }},
    {'-', [](double first, double second, auto* out ) { *out = first - second; return ErrorCode::OK; }},
    {'*', [](double first, double second, auto* out ) { *out = first * second; return ErrorCode::OK; }},
    {'/', [](double first, double second, auto* out ) { *out = first / second; return ErrorCode::OK; }},
    {'%', [](int first, int second, auto* out ) { *out = first % second; return ErrorCode::OK; }},
    {'!', [](double first, [[maybe_unused]] double second, auto* out ) { *out = tgamma(first+1); return ErrorCode::OK; }},
    {'^', [](double first, double second, auto* out ) { *out = pow(first,second); return ErrorCode::OK; }},
    {'$', [](double first, double second, auto* out ) { *out = pow(first,1/double(second)); return ErrorCode::OK; }},

};

// ErrorCode process(std::string, double*);