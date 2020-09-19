#pragma once
#include <functional>
#include <map>
#include <string>
#include <vector>

enum class ErrorCode {
    OK,
    BadFormat,
    BadCharacter,
    DivideBy0,
    ModuleOfNonIntegerValue,
    SqrtOfNagativeNumber
};

std::string eraseSpaces(std::string input);
ErrorCode allowedCharacters(std::string input);
ErrorCode allowedFormat(std::string input);
std::vector<std::string> unpackExpression(std::string input);
ErrorCode prohibitedOperations(std::vector<std::string> unpackedElements);

using specMap = std::map<char, std::function<double(double,double)>>;
double calculate(specMap actionsHolder, std::vector<std::string> unpackedElements);

ErrorCode process(std::string input, double* out);
