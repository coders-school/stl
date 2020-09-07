#pragma once

#include <cmath>

class mathematicalOperation {
public:
    static double add(const double& firstValue, const double& secondValue) {
        return firstValue + secondValue;
    }

    static double subtract(const double& firstValue, const double& secondValue) {
        return firstValue - secondValue;
    }

    static double multiply(const double& firstValue, const double& secondValue) {
        return firstValue * secondValue;
    }

    static double divide(const double& firstValue, const double& secondValue) {
        return firstValue / secondValue;
    }

    static double power(const double& firstValue, const double& secondValue) {
        return std::pow(firstValue, secondValue);
    }

    static double sqrt(const double& firstValue, const double& secondValue) {
        return std::pow(firstValue, (1 / secondValue));
    }

    static double modulo(const double& firstValue, const double& secondValue) {
        return static_cast<int>(firstValue) % static_cast<int>(secondValue);
    }

    static double factorial(const double& firstValue, const double& secondValue) {
        if (firstValue < 0)
            return 1.0;
        else {
            return firstValue * tgamma(firstValue);
        }
    }
};
