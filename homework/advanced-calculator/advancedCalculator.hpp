#pragma once

#include <cmath>
#include <functional>
#include <map>
#include <string>

enum ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

const std::map<char, std::function<double(double, double)>> commands {
    {'+', [](auto x, auto y){ return std::plus<>{}(x, y); } },
    {'-', [](auto x, auto y){ return std::minus<>{}(x, y); } },
    {'/', [](auto x, auto y){ return std::divides<>{}(x, y); } },
    {'*', [](auto x, auto y){ return std::multiplies<>{}(x, y); } },
    {'%', [](auto x, auto y){ return (int)x % (int)y; } },
    {'!', [](auto x, auto y){ return std::tgamma(x); } },
    {'^', [](auto x, auto y){ return std::pow(x, y); } },
    {'$', [](auto x, auto y){ return std::sqrt(x); } }
};

void getUserInput ();
bool checkUserInput (std::string &input);
bool isPlayerChoiceValid(std::string &playerAnswer);
ErrorCode process(std::string, double*);