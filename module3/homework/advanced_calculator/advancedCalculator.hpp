#pragma once
#include <functional>
#include <map>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

class Calculator {
private:
    static double add(double a, double b);
    static double substract(double a, double b);
    static double multiplicate(double a, double b);
    static double divide(double a, double b);
    static double modulo(double a, double b);
    static double factorial(double a, double b = 0);
    static double power(double a, double b);
    static double root(double a, double b);

    static std::map<char, std::function<double(double, double)>> possibleFunctions;

public:
    static double calculate(char operation, double a, double b = 0);
};
