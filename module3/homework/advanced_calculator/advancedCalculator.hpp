#pragma once

#include <iostream>
#include <string>

enum class ErrorCode {
    OK,
    BadFormat,
    DivideBy0,
    BadCharacter,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode process(std::string, double*);
void calculate(std::string&);