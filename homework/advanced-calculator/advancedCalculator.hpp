#pragma once

#include <string>

enum class ErrorCode {
    OK,
    BadFormat,
    BadCharacter,
    DivideBy0,
    ModuleOfNonIntegerValue,
    SqrtOfNegativeNumber
};

bool isBadCharacter(const std::string&);
bool isInteger(double);

ErrorCode process(const std::string&, double* const);
