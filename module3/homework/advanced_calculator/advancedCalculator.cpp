#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <map>

std::map<char, std::function<double(double, double)>> commands{{'+', std::plus<double>()},
                                                               {'-', std::minus<double>()},
                                                               {'*', std::multiplies<double>()},
                                                               {'/', std::divides<double>()},
                                                               {'%', std::modulus<int>()},
                                                               {'^', [](double base, double exponent) { return pow(base, exponent); }},
                                                               {'$', [](double num, double root) { return pow(num, 1.0 / root); }},
                                                               {'!', [](double num, double whatever = 0.0) { return tgamma(num + 1.0); }}};

ErrorCode process(const std::string& input, double* out) {
    return ErrorCode::OK;
}
