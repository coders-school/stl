#pragma once
#include <algorithm>
#include <iostream>
#include <functional>
#include <map>
#include <math.h>

enum class ErrorCode
{
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

ErrorCode process(std::string input, double*);
ErrorCode operations(char, double, double, double*);
ErrorCode divide(double, double, double*);
ErrorCode factorial(double, double, double*);
ErrorCode nth_root(double, double, double*);
ErrorCode modulo(double, double, double*);

int operatorPosition(const std::string&);
bool BadCharacter(const std::string&);
bool BadFormat(const std::string&);
double parseFirst(const std::string&);
double parseSecond(const std::string&, int);

bool comma(const std::string&);
bool factorialBadFormat(const std::string&);
bool tooLong(const std::string&);
bool dots(const std::string&);
