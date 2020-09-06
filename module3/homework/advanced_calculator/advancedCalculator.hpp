#pragma once

#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNagativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode process(std::string input, double* out);
bool checkCharacter(const std::string& input);
bool checkComas(const std::string& input);
void removeSpaces(std::string& input);
ErrorCode takeNumbers(const std::string& input, double& num1, char& operation, double& num2);
