#pragma once
#include <string>

enum class ErrorCode{
    Ok,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

bool isIntiger(double value);
double factorial(double value);
bool badCharacter(std::string input);

ErrorCode process(std::string input, double* out);

