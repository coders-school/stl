#pragma once

#include <string>
#include <map>
#include <functional>

#include "errorCodes.hpp"
#include "formulaParser.hpp"

using FunctionMap = std::map<char, std::function<double(double,double)>>;

double division(double a, double b);
double factorial(double a, double b);
double power(double a, double b);
double squareRoot(double a, double b);
double modulo(double a, double b);

double calculate(FormulaParser & fp);

ErrorCode process(std::string input, double* out);



