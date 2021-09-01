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
    ModuleOfNonIntegerValue,
    Undefined
};

const std::map<char, std::function<double(double, double)>> commands {
    {'+', std::plus<double>{} },
    {'-', std::minus<double>{} },
    {'/', std::divides<double>{} },
    {'*', std::multiplies<double>{} },
    {'%', [](auto lhs, auto rhs){ return (int)lhs % (int)rhs; } },
    {'!', [](auto lhs, auto rhs){ return lhs > 0 ? std::tgamma(lhs + 1) : std::tgamma(-lhs + 1)*-1; } },
    {'^', [](auto lhs, auto rhs){ return std::pow(lhs, rhs); } },
    {'$', [](auto lhs, auto rhs){ return std::pow(lhs, 1.0/rhs); } }
};


ErrorCode process (std::string, double*);
bool validateCharacters (const std::string & input);
bool validateFormat (std::string &input);
bool isAllowedChar (char c);
char findCommand (std::string &input, std::string &allowedChars);
double parseLhs (std::string &input, std::string::size_type &sz);
double parseRhs (std::string &input, std::string::size_type &sz, char &operation);
bool checkFormatSymbols (char &c);
bool isInteger (double num);