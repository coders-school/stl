#pragma once
#include <string>
#include "ExpressionParser.hpp"


enum class ErrorCode
{
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};


ErrorCode process(std::string input, double* out);