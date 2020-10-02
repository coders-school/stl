#pragma once

#include <map>
#include <string>
#include <vector>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

void removeSpaces(std::string& input);
double factorial(double num);
bool checkCharacter(const std::string& input);

const std::map<ErrorCode, std::string> errorOutput{
    {ErrorCode::OK, "All is OK\n"},
    {ErrorCode::BadCharacter, "Bad charcter\n"},
    {ErrorCode::BadFormat, "Bad Format\n"},
    {ErrorCode::DivideBy0, "Divide by 0\n"},
    {ErrorCode::ModuleOfNonIntegerValue, "Module of non integer value\n"},
    {ErrorCode::SqrtOfNegativeNumber, "Sqrt of negative number\n"}};

ErrorCode extractPattern(const std::string& input, std::vector<std::string>* out);
ErrorCode checkOperatorCode(const double& firstNum, const double& secondNum, const char& op);
ErrorCode process(std::string input, double* out);
