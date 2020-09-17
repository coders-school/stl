#pragma once

#include <string>

#include "errorCodes.hpp"
#include "formulaParser.hpp"

using FunctionMap = std::map<char, std::function<double(double,double)>>;

FunctionMap functions{
        {'+', std::plus<double>()},
        {'-', std::minus<double>()},
        {'*', std::multiplies<double>()},
        {'/', division},
        {'!', factorial},
        {'^', power},
        {'$', squareRoot},
        {'%', modulo}
};

double division(double a, double b);
double factorial(double a, double b);
double power(double a, double b);
double squareRoot(double a, double b);
double modulo(double a, double b);

double calculate(FormulaParser & fp);

ErrorCode process(std::string input, double* out);


