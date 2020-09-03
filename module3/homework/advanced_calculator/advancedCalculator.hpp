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

class Calculations {
private:
    static double add(double a, double b);
    static double substract(double a, double b);
    static double multiplicate(double a, double b);
    static double divide(double a, double b);
    static double modulo(double a, double b);
    static double factorial(double a, double b = 0);
    static double power(double a, double b);
    static double root(double a, double b);

public:
    std::map<char, std::function<double(double, double)>> possibleActions = {
        {'+', Calculations::add},
        {'-', Calculations::substract},
        {'*', Calculations::multiplicate},
        {'/', Calculations::divide},
        {'%', Calculations::modulo},
        {'!', Calculations::factorial},
        {'^', Calculations::power},
        {'$', Calculations::root}};
};