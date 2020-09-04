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

ErrorCode process(std::string input, double* out);

//BadCharacters
bool checkCharacters(std::string input);

//BadFormat
void removeSpaces(std::string& input);
size_t findOperation(std::string input);
std::pair<std::string, std::string> separateNums(std::string input, size_t distance);
bool checkFirstChar(std::string input);
bool checkNumber(std::string input);

bool checkIfDividedByZero(std::string input, size_t distance, double secondNum);
bool checkSqrtOfNegativeNumber(std::string input, size_t distance, double firstNum);
bool checkIfModuloOfNonIntegerValue(std::string input, size_t distance, std::pair<std::string, std::string> pair);
