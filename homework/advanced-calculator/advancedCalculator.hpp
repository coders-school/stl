#include <iostream>
#include <functional>
#include <map>
#include <string>

enum class ErrorCode
{
    Ok,
    BadCharacter,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

ErrorCode process(std::string input, double* out);
