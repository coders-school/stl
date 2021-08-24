#pragma once
#include <functional>
#include <map>
#include <optional>
#include <vector>
#include "ErrorCode.hpp"

using Value = double;
struct CalculationResult {
    ErrorCode errorCode;
    std::optional<Value> value;
};

using Numbers = std::vector<Value>;
using CalculationFunction = std::function<CalculationResult(Numbers::const_iterator, Numbers::const_iterator)>;
using CommandsMap = std::map<char, CalculationFunction>;