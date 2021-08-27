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
    { '!', [](auto n, [[maybe_unused]]auto x) { return n <= 0 ? 1.0 : std::tgamma(n + 1.0); } }
};
} // namespace calc

ErrorCode process(std::string input, double* out) {
    std::istringstream iss(input);
    std::vector<std::string> expressions{std::istream_iterator<std::string>(iss), {}};
    
    std::string LHS, RHS;
    double lhs, rhs;
    char operation;
    int badchar = 0, badform = 0, divby0 = 0, modofnonint = 0, sqrtofneg = 0;
    // parse vector (or string directly)
    // to operation type and its arguments (lhs & rhs or lhs for factorial)
    for(const auto & letter : input) {
        if(operation == '\0'){
            if((letter >= 48 && letter <= 57) || letter == '.') {
                LHS.push_back(letter);
            }
            // if((letter < 46 || letter == 47 || letter > 57) && letter != 32) {
            //     return ErrorCode::BadCharacter;
            // }
        }
        for(const auto & iter : calc::calculations) {
            if(LHS.empty() == false && operation == '\0' && letter == iter.first) {
                operation = letter;
            }
            if(LHS.empty() == false && operation == '\0' && (letter != iter.first || letter != ' ' || !(letter >= 48 && letter <= 57) || letter != '.')) {
                badchar++;
            }
            if(operation != '\0' && letter == iter.first) {
                badform++;
            }
        }
        if(operation != '\0') {
            if((letter >= 48 && letter <= 57) || letter == '.') {
                RHS.push_back(letter);
            }
            // if((letter < 46 || letter == 47 || letter > 57) && letter != 32) {
            //     return ErrorCode::BadCharacter;
            // }
        }
    }
    
    if(badform >= calc::calculations.size() || LHS.empty() == true) {
        return ErrorCode::BadFormat;
    }
    if(badchar >= calc::calculations.size()) {
        return ErrorCode::BadCharacter;
    }

    lhs = std::stod(LHS);
    rhs = std::stod(RHS);

    if(rhs == 0 && operation == '/') {
        return ErrorCode::DivideBy0;
    }

    // char operation{ '+' };      // example
    // double lhs{ 2 };            // example
    // double rhs{ 3 };            // example


    
    /* return error code if input cannot be parsed correctly
    //return ErrorCodeBadFormat;
    // return ErrorCodeBadCharacter;
    return ErrorCodeDivideBy0;
    return ErrorCodeModuleOfNonIntegerValue;
    return ErrorCodeSqrtOfNegativeNumber;
    */

    // otherwise calculate and return OK
    *out = calc::calculations.at(operation)(lhs, rhs);

    return ErrorCode::OK;
}
