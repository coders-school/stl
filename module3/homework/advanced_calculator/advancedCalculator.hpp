#pragma once

#include <string>

enum class ErrorCode { 
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode process(const std::string input, double* out);
