#pragma once
#include <string>
#include <map>
#include<cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <vector>
#include <iostream>
#include <type_traits>

enum ErrorCode{
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};
ErrorCode process(std::string input, double* out);