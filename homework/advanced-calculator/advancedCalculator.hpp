#pragma once
#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
    Undefined
};

struct Operation {
    double a;
    char sign;
    double b;
};

ErrorCode parse(const std::string&, Operation&);
ErrorCode process(const std::string&, double*);
