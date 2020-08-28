#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <map>

std::map<char, std::function<double(double, double)>> commands{{'+', std::plus<double>()},
                                                               {'-', std::minus<double>()},
                                                               {'*', std::multiplies<double>()},
                                                               {'/', std::divides<double>()},
                                                               {'%', std::modulus<int>()},
                                                               {'^', [](double lhs, double rhs) { return pow(lhs, rhs); }},
                                                               {'$', [](double lhs, double rhs) { return pow(lhs, 1.0 / rhs); }},
                                                               {'!', [](double lhs, double rhs = 0.0) { return tgamma(lhs + 1.0); }}};

ErrorCode process(const std::string& input, double* out) {
    return ErrorCode::OK;
}
