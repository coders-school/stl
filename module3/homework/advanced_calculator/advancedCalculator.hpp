#pragma once
#include <functional>
#include <map>
#include <string>

enum class ErrorCode {
    OK,
    BadFormat,
    BadCharacter,
    DivideBy0,
    ModuleOfNonIntegerValue,
    SqrtOfNagativeNumber
};

std::string eraseSpaces(std::string input);
ErrorCode allowedCharacters(std::string input);

ErrorCode process(std::string input, double* out);
