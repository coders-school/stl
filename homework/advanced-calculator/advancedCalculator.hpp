#pragma once

#include <functional>
#include <map>
#include <string>

using MapContainer = const std::map<const char, const std::function<double(const double&, const double&)>>;

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

double moduloOperation(const double& a, const double& b);
double factorialOperation(const double& a, const double& b);

ErrorCode process(std::string input, double* out);
ErrorCode validateOperation(const std::string& input, double& a, double& b, char& operationSign);
ErrorCode parseValue(const std::string& input, std::string& output, std::string::const_iterator& it);
char parseOperator(const std::string& input, std::string::const_iterator& it);
