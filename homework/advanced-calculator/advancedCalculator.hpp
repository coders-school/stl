#ifndef ADVANCEDCALCULATOR_HPP
#define ADVANCEDCALCULATOR_HPP

#include <string>

enum ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode process(std::string input, double* out);

#endif
