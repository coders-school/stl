
#pragma once
#include <cmath>
#include <functional>
#include <map>
#include <regex>
#include <string>

namespace Pattern {
const auto expression = R"(^([-]?\d+\.\d+|[-]?\d+)\s?([+*/\-%^$])\s?([-]?\d+\.\d+|[-]?\d+))";
const auto factiorial = R"(([-]?\d+\.\d+|[-]?\d+)\s?(\!))";
}  // namespace Pattern

enum OperationType {
    TwoArguments,
    Factorial,
    Bad
};

const std::map<char, std::function<double(double, double)>> operations{
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    {'%', std::modulus<int>()},
    {'^', [](double base, double pow) { return std::pow(base, pow); }},
    {'$', [](double base, double root) { return std::pow(base, 1.0 / root); }}};

enum ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

const std::map<ErrorCode, std::string> errorCodeString{
    {ErrorCode::OK, "OK"},
    {ErrorCode::BadCharacter, "Error: Expression contains bad character"},
    {ErrorCode::BadFormat, "Error: Expression has bad format"},
    {ErrorCode::DivideBy0, "Error: Divide by 0 is not allowed"},
    {ErrorCode::SqrtOfNegativeNumber, "Error: Result is not real number"},
    {ErrorCode::ModuleOfNonIntegerValue, "Error: Modulo operation required interger argument"}};

void compute(std::string& input);
ErrorCode process(std::string input, double* out);
OperationType GetOperationType(const std::string& input, std::smatch& matches);
ErrorCode computeFactorialExpression(std::smatch& matches, double* out);
ErrorCode computeTwoArgumentsExpression(std::smatch& matches, double* out, std::string& input);
bool isBadCharacter(std::string& input);
bool isInteger(double& val);