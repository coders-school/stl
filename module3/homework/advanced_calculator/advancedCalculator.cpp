#include "advancedCalculator.hpp"
#include <cmath>

double Calculator::add(double a, double b) {
    return a + b;
}
double Calculator::substract(double a, double b) {
    return a - b;
}
double Calculator::multiplicate(double a, double b) {
    return a * b;
}
double Calculator::divide(double a, double b) {
    return a / b;
}
double Calculator::modulo(double a, double b) {
    return static_cast<int>(a) % static_cast<int>(b);
}
double Calculator::factorial(double a, double b) {
    if (0 == a || 1 == a) {
        return 1;
    }
    return a * std::tgamma(a);
}
double Calculator::power(double a, double b) {
    return std::pow(a, b);
}
double Calculator::root(double a, double b) {
    return pow(a, 1 / b);
}

double Calculator::calculate(char operation, double a, double b) {
    return possibleFunctions[operation](a, b);
}

std::map<char, std::function<double(double, double)>> Calculator::possibleFunctions = {
    {'+', Calculator::add},
    {'-', Calculator::substract},
    {'*', Calculator::multiplicate},
    {'/', Calculator::divide},
    {'%', Calculator::modulo},
    {'!', Calculator::factorial},
    {'^', Calculator::power},
    {'$', Calculator::root}};