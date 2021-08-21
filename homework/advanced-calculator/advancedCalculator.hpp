#pragma once
#include <map>
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
    {'+', [](double first, double second, double* out ) { *out = first + second; return ErrorCode::OK; }},
    {'-', [](double first, double second, double* out ) { *out = first - second; return ErrorCode::OK; }},
    {'*', [](double first, double second, double* out ) { *out = first * second; return ErrorCode::OK; }},
    {'/', [](double first, double second, double* out ) { *out = first / second; return ErrorCode::OK; }},
};

// ErrorCode process(std::string, double*);