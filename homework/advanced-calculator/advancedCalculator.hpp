#pragma once

#include <string>
#include <map>
#include <array>
#include <functional>

using ArgsArray = std::array<double, 2>;
using MapContainer = std::map<const char, const std::function<double(const ArgsArray&)>>;

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

ErrorCode parseStr(std::string& input, ArgsArray& arr, std::string::iterator& opr);
ErrorCode process(std::string input, double* out);
