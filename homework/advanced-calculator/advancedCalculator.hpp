#ifndef ADVANCEDCALCULATOR.HPP
#define ADVANCEDCALCULATOR.HPP

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
    //{'%', std::modulus<int>()},
    {'!', [](auto lhs, auto rhs){ return lhs > 0 ? std::tgamma(lhs + 1) : std::tgamma(-lhs + 1)*-1; } },
    {'^', [](auto lhs, auto rhs){ return std::pow(lhs, rhs); } },
    {'$', [](auto lhs, auto rhs){ return std::pow(lhs, 1.0/rhs); } }
};


ErrorCode process (std::string input, double* out );

#endif