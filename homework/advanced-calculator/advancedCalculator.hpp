#ifndef ADVANCED_CALCULATOR_H
#define ADVANCED_CALCULATOR_H

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <functional>
#include <cmath>
#include <sstream>
#include <cctype>
#include <vector>
#include <set>
#include <iterator>

enum class ErrorCode {OK = 0, BadCharacter, BadFormat, DivideBy0, SqrtOfNegativeNumber, ModuleOfNonIntegerValue};
ErrorCode process(std::string input, double* out);
// returns true if string is a number else false
bool isNumber(std::string);
// return true if c is an element of set
bool isValidCharacter(char c, const std::set<char>& set);
bool isInteger(double val);

#endif