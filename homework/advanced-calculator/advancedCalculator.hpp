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
    {'+', std::plus<double>{} },
    {'-', std::minus<double>{} },
    {'/', std::divides<double>{} },
    {'*', std::multiplies<double>{} },
    {'%', std::modulus<int>{} },
    {'!', [](auto x, auto y){ return x > 0 ? std::tgamma(x + 1) : std::tgamma(-x + 1)*-1; } },
    {'^', [](auto x, auto y){ return std::pow(x, y); } },
    {'$', [](auto x, auto y){ return std::pow(x, 1/y); } }
};

std::string getUserInput ();
bool validateCharacters (std::string &input);
bool isInputValid (std::string &input);
ErrorCode process (std::string, double*);
bool validateFormat (std::string &input);