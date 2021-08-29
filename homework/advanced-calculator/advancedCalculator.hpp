#pragma once
#include <functional>
#include <cmath>
#include <map>

enum ErrorCode {
    Ok,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode process(std::string input, double* out);

std::function<int(int, int)> add = [](auto x, auto y){ return x + y; }; 
std::function<int(int, int)> substract = [](auto x, auto y){ return x - y; }; 
std::function<int(int, int)> divide = [](auto x, auto y){ return x / y; }; 
std::function<int(int, int)> multiply = [](auto x, auto y){ return x * y; }; 
std::function<int(int, int)> modulo = [](auto x, auto y){ return x % y; }; 
std::function<int(int, int)> factorial = [](auto x, auto y){ return x + y; }; 
std::function<int(int, int)> pow = [](auto x, auto y){ return std::pow(x, y); }; 
std::function<int(int, int)> sqr = [](auto x, auto y){ return x + y; }; 

std::map<char,  std::function<int(int, int)>> calculatorCommands = {
    {'+', add },
    {'-', substract },
    {'/', divide },
    {'*', multiply },
    {'%', modulo },
    {'!', factorial },
    {'^', pow },
    {'$', sqr }
};


void checkUserInput (std::string input);