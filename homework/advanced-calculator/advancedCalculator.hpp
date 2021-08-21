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

ErrorCode process(std::string input, double* out);
std::string parseValue(const std::string& input, std::string::const_iterator& it);
char parseOperator(const std::string& input, std::string::const_iterator& it);
