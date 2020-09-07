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
    ModuleOfNonIntegerValue
};

void printInfo();

double factorial(double);
bool badChar(const std::string& input);
bool isInteger(double num);

std::vector<std::string> getEquation(const std::string& input);
ErrorCode validation(double num1, double num2, char op);
ErrorCode process(std::string input, double* out);

std::string getErrorMsg(ErrorCode ec);
