#pragma once

#include <string>

enum class ErrorCode {
    Ok,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode process(std::string input, double* out);

//BadCharacters
bool checkCharacters(std::string input);

//BadFormat
void removeSpaces(std::string& input);
size_t findOperation(std::string input);
std::pair<std::string, std::string> separateNums(std::string input, size_t distance);
bool checkFirstChar(std::string input);
bool checkNumber(std::string input);
