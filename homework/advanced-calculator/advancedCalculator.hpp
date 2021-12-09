#pragma once 
#include <cmath>
#include <string>
#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <memory>

enum ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

extern std::map<char, std::function<double(double a, double b)>> Wrapper;


ErrorCode process(std::string input, double* out);
