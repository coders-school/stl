#pragma once

#include "ErrorCode.hpp"
#include <optional>
#include <map>
#include <vector>
#include <functional>

using Value = double;
struct CalculationResult{
    ErrorCode errorCode;
    std::optional<Value> value;
};

using CommandToken = char;
using Numbers = std::vector<Value>;
using CalculationFunction = std::function<CalculationResult(Numbers::const_iterator, Numbers::const_iterator)>;
using CommandsMap = std::map<CommandToken, CalculationFunction>;

extern CommandsMap commands;