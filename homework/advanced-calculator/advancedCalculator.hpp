#ifndef ADVANCEDCALCULATOR_HPP 
#define ADVANCEDCALCULATOR_HPP 

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
};


ErrorCode process (std::string input, double* out );
bool validateInput(const std::string& input);
bool isFactorial(const std::string& input);
double parseLHS(const std::string& input);
char parseOperator(const std::string& input, int& offset);
double parseRHS(const std::string& input, const int&offset);
bool hasBadCharacters(const std::string& input);
bool isInteger (const double& num);
bool hasDoubleMinus(const std::string& input);

#endif