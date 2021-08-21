#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <iterator>
#include <map>
#include <sstream>
#include <vector>

namespace calc {
std::map<char, std::function<double(double, double)>> calculations{
    { '+', std::plus<>() },
    { '-', std::minus<>() },
    { '*', std::multiplies<>() },
    { '/', std::divides<>() },
    { '%', std::modulus<int>() },
    { '^', [](auto base, auto exponent) { return std::pow(base, exponent); } },
    { '$', [](auto base, auto root) { return std::pow(base, 1.0 / root);} },
    { '!', [](auto n, [[maybe_unused]]auto x) {return n <= 0 ? 1.0 : std::tgamma(n + 1.0); } }
};
} // namespace calc

ErrorCode process(std::string input, double* out) {
    std::istringstream iss(input);
    std::vector<std::string> expressions{std::istream_iterator<std::string>(iss), {}};

    // parse vector (or string directly)
    // to operation type and its arguments (lhs & rhs or lhs for factorial)

    char operation{ '+' };      // example
    double lhs{ 2 };            // example
    double rhs{ 3 };            // example

    /* return error code if input cannot be parsed correctly
    return ErrorCodeBadFormat;
    return ErrorCodeBadCharacter;
    return ErrorCodeDivideBy0;
    return ErrorCodeModuleOfNonIntegerValue;
    return ErrorCodeSqrtOfNegativeNumber;
    */

    // otherwise calculate and return OK
    *out = calc::calculations.at(operation)(lhs, rhs);

    return ErrorCode::OK;
}
