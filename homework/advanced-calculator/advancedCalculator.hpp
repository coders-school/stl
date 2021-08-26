#pragma once
#include <cmath>
#include <functional>
#include <map>
#include <string>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

bool is_not_integer(double);
bool loadNumber(std::string&, double&);
bool loadCharacter(std::string&, char&);
bool BadCharacter(const std::string&);
bool characterCountTest(const std::string&);
bool BadFormat(std::string, double&, double&, char&);
ErrorCode process(std::string, double*);



inline std::map<char, std::function<ErrorCode(double first, double second, double* out)>> calculator_functions = {
    {'+', [](double first, double second, auto* out) { *out = first + second; return ErrorCode::OK; }},
    {'-', [](double first, double second, auto* out) { *out = first - second; return ErrorCode::OK; }},
    {'*', [](double first, double second, auto* out) { *out = first * second; return ErrorCode::OK; }},
    {'/', [](double first, double second, auto* out) { *out = first / second; return ErrorCode::OK; }},
    {'%', [](int first, int second, auto* out) { *out = first % second; return ErrorCode::OK; }},
    {'!', [](double first, [[maybe_unused]] double second, auto* out) {
         (first > 0) ? * out = tgamma(first + 1.)
                     : * out = -tgamma(-first + 1.);
         return ErrorCode::OK;
     }},
    {'^', [](double first, double second, auto* out) { *out = pow(first,second); return ErrorCode::OK; }},
    {'$', [](double first, double second, auto* out) { *out = pow(first,1./second); return ErrorCode::OK; }},

};
