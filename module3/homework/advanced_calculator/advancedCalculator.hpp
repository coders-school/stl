#ifndef advancedCalculator_h
#define advancedCalculator_h

#include <iostream>
#include <map>
#include <vector>

enum class ErrorCode{
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,s
};

void removeSpaces(std::string&);
bool isInt(double);
std::vector<std::string> checkRegex(std::string);

bool badCharacter(std::string);
bool divideByZero(double, std::string);
bool sqrtOfNegativeNumber(double, std::string);
bool moduleOfNonIntegerValue(double, double, std::string);
bool badFormat(std::vector<std::string>);

ErrorCode process(std::string, double*);

#endif