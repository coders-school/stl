#pragma once
#include <string>

enum class ErrorCode {
    Ok,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode process(std::string, double*);
