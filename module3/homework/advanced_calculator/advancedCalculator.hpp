#ifndef advancedCalculator_h
#define advancedCalculator_h

#include <iostream>
#include <map>
#include <functional>
#include <regex>

enum class ErrorCode{
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

void removeSpaces(std::string&);
bool isInt(double);
std::vector<std::string> expressionRegex(std::string);

bool badCharacter(std::string);
bool divideByZero(std::vector<std::string>);
bool sqrtOfNegativeNumber(std::vector<std::string>);
bool moduleOfNonIntegerValue(std::vector<std::string>);

ErrorCode process(std::string, double*);




#endif