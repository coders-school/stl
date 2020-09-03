#include "advancedCalculator.hpp"
#include <cmath>

double Calculations::add(double a, double b) {
    return a + b;
}
double Calculations::substract(double a, double b) {
    return a - b;
}
double Calculations::multiplicate(double a, double b) {
    return a * b;
}
double Calculations::divide(double a, double b) {
    return a / b;
}
double Calculations::modulo(double a, double b) {
    return static_cast<int>(a) % static_cast<int>(b);
}
double Calculations::factorial(double a, double b) {
    if (1 == 0 || 1 == a) {
        return 1;
    }
    return a * std::tgamma(a);
}
double Calculations::power(double a, double b) {
    return std::pow(a, b);
}
double Calculations::root(double a, double b) {
    return pow(a, 1 / b);
}

double Calculations::calculate(char operation, double a, double b) {
    return possibleFunctions[operation](a, b);
}
