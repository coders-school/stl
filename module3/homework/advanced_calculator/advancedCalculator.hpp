#pragma once
#include <string>

enum class ErrorCode {
    OK,
    BadFormat,
    BadCharacter,
    DivideBy0,
    ModuleOfNonIntegerValue,
    SqrtOfNagativeNumber
};

ErrorCode process(std::string input, double* out);
