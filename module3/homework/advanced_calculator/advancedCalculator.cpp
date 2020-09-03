#include "advancedCalculator.hpp"
#include <math.h>

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
double Calculations::factorial(double a, double b = 0) {
    if (a < 0) {
        return 1;
    }
}
double Calculations::power(double a, double b) {
    return std::pow(a, b);
}
double Calculations::root(double a, double b) {
    return pow(a, 1 / b);
}
