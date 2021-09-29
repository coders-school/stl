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

struct Operation {
    double a;
    char sign;
    double b;
};

ErrorCode process(std::string, double*);
Operation parse(const std::string &);
