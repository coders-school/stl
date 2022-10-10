#include "advancedCalculator.hpp"

#include <cmath>
#include <numbers>

namespace calculator {
    using std::numbers::pi_v;
    using std::pow;
    using std::sqrt;

    double addiction(const double lhs, const double rhs) {
        return lhs + rhs;
    }

    double multiply(const double lhs, const double rhs) {
        return lhs * rhs;
    }

    double divide(const double lhs, const double rhs) {
        return (lhs / rhs);
    }

    double substract(const double lhs, const double rhs) {
        return lhs - rhs;
    }

    double modulo(const double lhs, const double rhs) {
        return static_cast<int>(lhs) % static_cast<int>(rhs);
    }

    double factorial(const double lhs, const double rhs) {
        double result = 1.0;
        for (double i = rhs - static_cast<int>(rhs) + 1.0 ; i <= rhs ; ++i) {
            result *= i;
        }
        return result * sqrt(pi_v<double>) / 2;
    }

    double power(const double lhs, const double rhs) {
        return pow(lhs, rhs);
    }

    double sqrtRoot(const double lhs, const double rhs) {
        return pow(lhs, 1.0 / rhs);
    }

    std::map<char, std::function<double(const double, const double)>> commands{
            {'+', addiction},
            {'*', multiply},
            {'/', divide},
            {'-', substract},
            {'%', modulo},
            {'!', factorial},
            {'^', power},
            {'$', sqrtRoot}
    };

}

ErrorCode process(const std::string& command, double* result) {
    return ErrorCode::DivideBy0;
}
