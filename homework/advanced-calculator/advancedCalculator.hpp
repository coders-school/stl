#pragma once
#include <cmath>
#include <functional>
#include <map>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

bool is_not_integer(double number);
bool loadNumber(std::string& value, double& number);
bool loadCharacter(std::string& value, char& sign);
bool BadCharacter(const std::string& value);
bool characterCountTest(const std::string& value);
bool BadFormat(std::string input, double& firstNumber, double& secondNumber, char& sign);
ErrorCode process(std::string input, double* out);

static std::map<char, std::function<ErrorCode(double first, double second, double* out)>> calculator_functions = {
    {'+', [](double first, double second, auto* out) { *out = first + second; return ErrorCode::OK; }},
    {'-', [](double first, double second, auto* out) { *out = first - second; return ErrorCode::OK; }},
    {'*', [](double first, double second, auto* out) { *out = first * second; return ErrorCode::OK; }},
    {'/', [](double first, double second, auto* out) { *out = first / second; return ErrorCode::OK; }},
    {'%', [](int first, int second, auto* out) { *out = first % second; return ErrorCode::OK; }},
    {'!', [](double first, [[maybe_unused]] double second, auto* out) {
         if (first < 0) {
             *out = tgamma(-first + 1);
             *out = -*out;
         } else {
             *out = tgamma(first + 1);
         }
         return ErrorCode::OK;
     }},
    {'^', [](double first, double second, auto* out) { *out = pow(first,second); return ErrorCode::OK; }},
    {'$', [](double first, double second, auto* out) { *out = pow(first,1/double(second)); return ErrorCode::OK; }},

};
