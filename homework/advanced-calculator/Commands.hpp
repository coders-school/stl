#pragma once

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <optional>
#include <set>
#include "ErrorCode.hpp"

using CalculationResult = std::pair<ErrorCode, std::optional<double>>;
using Numbers = std::vector<double>;
using CommandsMap = std::map<char, std::function<CalculationResult(Numbers::const_iterator, Numbers::const_iterator)>>;

extern CommandsMap commands;