#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <iterator>
#include <map>
#include <regex>
#include <sstream>
#include <vector>

namespace calc {
std::map<char, std::function<double(double, double)>> calculations{
    {'+', std::plus<>()},
    {'-', std::minus<>()},
    {'*', std::multiplies<>()},
    {'/', std::divides<>()},
    {'%', std::modulus<int>()},
    {'^', [](auto base, auto exponent) { return std::pow(base, exponent); }},
    {'$', [](auto base, auto root) { return std::pow(base, 1.0 / root); }},
    {'!', [](auto n, [[maybe_unused]] auto x) { return n < 0
                                                       ? -(std::tgamma(-n + 1.0))
                                                       : std::tgamma(n + 1.0); }
    }
};
} // namespace calc

bool isInteger(double number) {
    return std::floor(number) == number;
}

bool forbidenCharacter(const std::string& input) {
    const std::array<char, 21> legalCharacters{'+', '-', '*', '/', '%', '!', '^', '$', '.', ',',
                                               '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '};
    return std::any_of(input.begin(),
                       input.end(),
                       [legalCharacters](char ch) {
                           return std::find(legalCharacters.begin(),
                                            legalCharacters.end(),
                                            ch) == legalCharacters.end();
                       });
}

ErrorCode process(std::string input, double* out) {
    if (forbidenCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (std::find(input.begin(), input.end(), ',') != input.end()) {
        return ErrorCode::BadFormat;
    }
    std::smatch matcher;
    std::regex availableOperation(R"(([-]?\d+\.\d+|[-]?\d+)\s?([-+*\/%^$])\s?([-]?\d+\.\d+|[-]?\d+))");
    std::regex factorial(R"(([-]?\d+.\d+|[-]?\d+)\s?(!))");
    
    if (std::regex_search(input, matcher, availableOperation) ||
        std::regex_search(input, matcher, factorial) )
    {
        if (matcher[0] != input) {
            return ErrorCode::BadFormat;
        }
        std::string operation = matcher[2];
        double lhs = std::stod(matcher[1]);
        double rhs = (operation != "!" ? std::stod(matcher[3]) : 0);

        if (operation == "/" and rhs == 0) {
            return ErrorCode::DivideBy0;
        } else if (operation == "$" and lhs < 0) {
            return ErrorCode::SqrtOfNegativeNumber;
        } else if (operation == "%" and (!isInteger(lhs) or !isInteger(rhs))) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }
        *out = calc::calculations.at(operation[0])(lhs, rhs);

        return ErrorCode::OK;
    }
    
    return ErrorCode::BadFormat;
}
