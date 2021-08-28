#pragma once

#include <iostream>
#include <string>

enum class ErrorCode {
    OK,
    BadFormat,
    BadCharacter,
    DivideBy0,
    ModuleOfNonIntegerValue,
    SqrtOfNegativeNumber
};

bool forbidenCharacter(const std::string&);
bool isInteger(double);

ErrorCode process(std::string input, double* out);
