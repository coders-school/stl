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
    {'!', [](auto lhs, auto rhs){ return lhs > 0 ? std::tgamma(lhs + 1) : std::tgamma(-lhs + 1)*-1; } },
    {'^', [](auto lhs, auto rhs){ return std::pow(lhs, rhs); } },
    {'$', [](auto lhs, auto rhs){ return std::pow(lhs, 1.0/rhs); } }
};



bool validateCharacters (const std::string & input);
ErrorCode process (std::string, double*);
bool validateFormat (std::string &input);
char findCommand (std::string &input, std::string &allowedChars);
// bool validateOperations (std::string &);

bool isAllowedChar (char c);