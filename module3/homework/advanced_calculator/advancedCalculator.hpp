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
    SqrtOfNegativeNumber
};

std::string eraseSpaces(std::string& input);
ErrorCode allowedCharacters(const std::string& input);
ErrorCode allowedFormat(const std::string& input);
std::vector<std::string> unpackExpression(const std::string& input);
ErrorCode prohibitedOperations(const std::vector<std::string>& unpackedElements);

using specMap = std::map<char, std::function<double(double,double)>>;
double calculate(specMap actionsHolder, std::vector<std::string> unpackedElements);

ErrorCode process(std::string input, double* out);
