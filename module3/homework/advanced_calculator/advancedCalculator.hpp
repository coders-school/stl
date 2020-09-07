#pragma once
#include <string>
#include "mathematicalOperation.hpp"

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

ErrorCode process(std::string input, double* out);
bool checkBadCharacker(const std::string& input);
