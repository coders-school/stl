#pragma once
#include <functional>
#include <map>
#include <string>
#include <vector>

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
ErrorCode allowedFormat(std::string input);
std::vector<std::string> unpackExpression(std::string input);
ErrorCode prohibitedOperations(std::string input, std::vector<std::string> unpackedElements);

ErrorCode process(std::string input, double* out);
