#pragma once
#include <string>
#include <utility>

enum class ErrorCode
{
    OK,
    BadCharacter,             // operator other then a number
    BadFormat,                // bad command format, e.g. "+ 5 4" instead of "4 + 5"
    DivideBy0,                // attempt of division by zero
    SqrtOfNegativeNumber,     // attempt of getting Sqrt of negative numbber
    ModuleOfNonIntegerValue   // attempt of getting modulo of non integer value
};

using FormatedInput = std::tuple<ErrorCode, double, std::string, double>;

ErrorCode process(std::string input, double* out);

FormatedInput formatInput(const std::string& line);

bool quitRequested(std::string line);

void printInstructions();