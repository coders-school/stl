#pragma once

#include <map>
#include <string>
#include <vector>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

ErrorCode process(std::string input, double* out);
std::vector<std::string> splitInputParserString(std::string& input);
std::pair<char, std::pair<double, double>> splitInputParser(std::string& input);
double factorial(double value);
bool checkCharacters(std::string input);
bool checkFormat(std::string& input);
