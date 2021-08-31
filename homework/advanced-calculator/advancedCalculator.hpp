#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
#include <cmath>

bool is_integer(double);
bool badCharacter(const std::string &);
bool badFormat(std::string);

enum class ErrorCode
{
    Ok,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNagativeNumber,
    ModuleOfNonIntegerValue
};

static std::map<char, std::function<double(double, double)>> advanced_calculator{
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    {'%', std::modulus<int>()},
    {'^', [](double numOne, double numTwo){return pow(numOne, numTwo);}},
    {'$', [](double numOne, double numTwo){return pow(numOne, 1/numTwo);}},
    {'!', [silnia = 1](double numOne, double numTwo) mutable{
        for(int i = 1; i <= numOne; i++)
        {
            silnia *= i;
        }
        return silnia;
        }},
    };


ErrorCode process(const std::string &, double);