#include "advancedCalculator.hpp"
#include "calcExceptions.hpp"

#include <iostream>
#include <map>
#include <functional>
#include <math.h>

double division(double a, double b){
    if(b == 0)
        throw DivideBy0Exception();
    return a / b;
}

double factorial(double a, double b){
    if(a < 0)
        return 1;
    return tgamma(a + 1);
}

double power(double a, double b){
    return pow(a,b);
}

double squareRoot(double a, double b){
    if(a < 0)
        throw SqrtOfNegativeNumberException();
    return pow(a, 1 / b);
}

double modulo(double a, double b){
    if(fmod(a,1) != 0 || fmod(b,1) != 0)
        throw ModuleOfNonIntegerValueException();
    return fmod(a,b);
}

double calculate(FormulaParser & fp){
    auto function = functions[fp.symbol];
    return function(fp.numberOne, fp.numberTwo);
}

ErrorCode process(std::string input, double* out) try{
    FormulaParser fp(input);
    *out = calculate(fp);
    return ErrorCode::OK;
} catch (const CalcException & e) {
    return e.errorCode;
}


