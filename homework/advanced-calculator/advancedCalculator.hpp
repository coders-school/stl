#include <math.h>
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

enum ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode isValidInput(std::string input, double& a, double& b, char& op);
ErrorCode process(std::string input, double* out);