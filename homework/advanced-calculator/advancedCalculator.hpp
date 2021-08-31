#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
#include <cmath>

enum class errorCode
{
    Ok,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNagativeNumber,
    ModuleOfNonIntegerValue
};

std::map<char, std::function<double(double, double)>> calculator{
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    {'%', std::modulus<int>()},
    {'^', [](double numOne, double numTwo){return pow(numOne, numTwo);}},
    {'$', [](double numOne, double numTwo){return pow(numOne, 1/numTwo); }},
    };