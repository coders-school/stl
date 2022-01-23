#include <iostream>
#include <map>
#include <cmath>
#include <functional>
#include <algorithm>
#include <cctype>

enum class ErrorCode
{
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode process(std::string tempString, double *out);
void stringFormatting(std::string &tempStr);
ErrorCode BadCharacterCheck(const std::string &tempStr);
void extractingOperands(std::string &tempStr, std::string &stringNum1, std::string &stringOper, std::string &stringNum2);
ErrorCode BadFormatCheck(const std::string &stringNum1, const std::string &operation, const std::string &stringNum2);
ErrorCode DivideBy0Check(const char &oper, const double &num2);
ErrorCode SqrtOfNegativeNumberCheck(const double &num1, const char &oper, const double &num2);
ErrorCode ModuleOfNonIntegerValue(const double &num1, const double &oper, const double &num2);
double doMath(const double & num1, const char & oper, const double & num2);
