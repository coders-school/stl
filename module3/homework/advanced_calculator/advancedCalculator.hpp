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
bool checkCharacters(const std::string& input);

//BadFormat
void removeSpaces(std::string& input);
size_t findOperation(const std::string& input);
std::pair<std::string, std::string> separateNums(std::string input, const size_t& distance);
bool checkFirstChar(const std::string& input);
bool checkNumber(const std::string& input);

bool checkIfDividedByZero(const std::string& input, const size_t& distance, const double& secondNum);
bool checkSqrtOfNegativeNumber(const std::string& input, const size_t& distance, const double& firstNum);
bool checkIfModuloOfNonIntegerValue(const std::string& input, const size_t& distance, const std::pair<std::string, std::string>& pair);
