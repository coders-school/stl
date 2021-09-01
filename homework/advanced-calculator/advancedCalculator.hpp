#pragma once
#include <algorithm>
#include <iostream>
#include <functional>
#include <map>
#include <cmath>
#include <string>

enum ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
    END
};

const std::map<char, std::function<double(double, double)>> advanced_calculator {
    {'+', std::plus<double>{} },
    {'-', std::minus<double>{} },
    {'/', std::divides<double>{} },
    {'*', std::multiplies<double>{} },
    {'%', std::modulus<int>()},
    {'^', [](double numOne, double numTwo){ return std::pow(numOne, numTwo);}},
    {'$', [](double numOne, double numTwo){ return std::pow(numOne, 1.0/numTwo);}},
    {'!', [](double numOne, double numTwo){ return numOne > 0 ? std::tgamma(numOne + 1) : std::tgamma(-numOne + 1)*-1; } },
};

ErrorCode process (std::string, double*);
bool is_integer (double); 
bool badCharacter (const std::string &);
bool badFormat (std::string &);
bool isAllowedChar (char);
char checkCommand (std::string &);
double parseFirst (std::string &, std::string::size_type &);
double parseSecound (std::string &, std::string::size_type &, char &);
bool checkSymbols (char &);
