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

ErrorCode process(std::string input, double* out);
