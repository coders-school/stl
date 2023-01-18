#pragma once

#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};
};

ErrorCode process(std::string, double*);
