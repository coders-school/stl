#pragma once
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <string>
#include <vector>

enum class ErrorCode
{
OK,
BadCharacter,
BadFormat,
DivideBy0,
SqrtOfNegativeNumber,
ModuleOfNonIntegerValue
};

using parsedText = std::array<std::string, 3>;

struct dataAsDigits
{
    double a;
    char ch;
    double b;
};

bool isGoodCharacter(std::string inString);
bool isBadCharacter(std::string inString);
ErrorCode parse(std::string input, parsedText & parsedText);
std::string cleanFromSpaces(const std::string & str);
ErrorCode parsedTextMakeSens(parsedText & parsedText);
bool canBeDouble(std::string str);
dataAsDigits prepareData(const parsedText & parsedText);
ErrorCode process(std::string input, double* out);
void compute(dataAsDigits dataIn, double* out);
