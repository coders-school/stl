#include <iostream>
#include <functional>
#include <cctype>

enum class ErrorCode {
    Ok,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode process(std::string input, double* out);
ErrorCode divideOperation(double a, double b, double *result);
ErrorCode moduloOperation(double a, double b, double *result);
ErrorCode factorialOperation(double a, double, double* result);
ErrorCode sqrtOperation(double a, double b, double *result);


