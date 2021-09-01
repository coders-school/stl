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
    Undefined
};


ErrorCode process (std::string input, double* out );
bool validateCharacters (const std::string & input);
bool validateFormat (std::string &input);
bool isAllowedChar (char c);
char findCommand (std::string &input, std::string &allowedChars);
double parseLhs (std::string &input, std::string::size_type &offset);
double parseRhs (std::string &input, std::string::size_type &offset, char &operation);
bool moreThanOperator (char &c);
bool isInteger (double num);

#endif