#pragma once
#include <iostream>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode process(std::string input, double* out);
ErrorCode findError(const std::string& input);
std::ostream& operator<<(std::ostream& out, const ErrorCode& err);
