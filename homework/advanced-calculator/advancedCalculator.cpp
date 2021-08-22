#include "advancedCalculator.hpp"
#include <map>
#include <cmath>

ErrorCode divideOperation(double a, double b, double *result) {
    if (b == 0) {
        return ErrorCode::DivideBy0;
    }
    else {
        *result = a / b;
        return ErrorCode::Ok;
    }
}

ErrorCode moduloOperation(double a, double b, double *result) {
    if (a != static_cast<int>(a) && b != static_cast<int>(b)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    else {
        *result = std::fmod(a, b);
        return ErrorCode::Ok;
    }
}

ErrorCode factorialOperation(double a, double, double *result) {
    if (a < 0) {
        a *= -1;
        *result = std::tgamma(a + 1) * -1;
    }
    else {
        *result = std::tgamma(a + 1);
    }
    return ErrorCode::Ok;
}

ErrorCode sqrtOperation(double a, double b, double *result) {
    if(a < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    else {
        *result = std::pow(a, 1 / b);
    }
    return ErrorCode::Ok;
}

std::map<char, std::function<ErrorCode(double, double, double *)>> operation = {
        {'+', [](double a, double b, double *result) {
            *result = a + b;
            return ErrorCode::Ok;
        }},
        {'-', [](double a, double b, double *result) {
            *result = a - b;
            return ErrorCode::Ok;
        }},
        {'*', [](double a, double b, double *result) {
            *result = a * b;
            return ErrorCode::Ok;
        }},
        {'^', [](double a, double b, double *result) {
            *result = std::pow(a, b);
            return ErrorCode::Ok;
        }},
        {'/', divideOperation},
        {'%', moduloOperation},
        {'!', factorialOperation},
        {'$', sqrtOperation}
};

/*
ErrorCode wrongCharacter(double a, double b, double *result) {

}*/
