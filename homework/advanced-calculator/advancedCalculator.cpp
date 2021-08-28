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
    {'!', [](auto n, [[maybe_unused]] auto x) { return n <= 0 ? 1.0 : std::tgamma(n + 1.0); }}};
}  // namespace calc
bool isInteger(double number) {
    return std::floor(number) == number;
}
bool forbidenCharacter(const std::string& input) {
    const std::array<char, 21> legalCharacters{'+', '-', '*', '/', '%', '!', '^', '$', '.', ',',
                                               '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '};
    return !std::none_of(input.begin(), input.end(), [legalCharacters](char ch) {
        return std::find(legalCharacters.begin(), legalCharacters.end(), ch) == legalCharacters.end();
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

    if (std::regex_search(input, matcher, availableOperation)) {
        if (matcher[0] != input) {
            return ErrorCode::BadFormat;
        }

        double lhs = std::stod(matcher[1]);
        double rhs = std::stod(matcher[3]);
        std::string operation = matcher[2];

        if ((operation == "/") and (rhs == 0)) {
            return ErrorCode::DivideBy0;
        } else if ((operation == "$") and (lhs < 0)) {
            return ErrorCode::SqrtOfNegativeNumber;
        } else if ((operation == "%") and (isInteger(lhs) or isInteger(rhs))) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }

        *out = calc::calculations.at(operation[0])(lhs, rhs);
        return ErrorCode::OK;
    }
    //  std::istringstream iss(input);
    //     std::vector<std::string> expressions{std::istream_iterator<std::string>(iss), {}};

    //     std::string LHS, RHS;
    //     double lhs, rhs;
    //     char operation;
    //     int badchar = 0, badform = 0, divby0 = 0, modofnonint = 0, sqrtofneg = 0;
    //     // parse vector (or string directly)
    //     // to operation type and its arguments (lhs & rhs or lhs for factorial)
    //     for(const auto & letter : input) {
    //         if(operation == '\0'){
    //             if((letter >= 48 && letter <= 57) || letter == '.') {
    //                 LHS.push_back(letter);
    //             }
    //             // if((letter < 46 || letter == 47 || letter > 57) && letter != 32) {
    //             //     return ErrorCode::BadCharacter;
    //             // }
    //         }
    //         for(const auto & iter : calc::calculations) {
    //             if(LHS.empty() == false && operation == '\0' && letter == iter.first) {
    //                 operation = letter;
    //             }
    //             if(LHS.empty() == false && operation == '\0' && (letter != iter.first || letter != ' ' || !(letter >= 48 && letter <= 57) || letter != '.')) {
    //                 badchar++;
    //             }
    //             if(operation != '\0' && letter == iter.first) {
    //                 badform++;
    //             }
    //         }
    //         if(operation != '\0') {
    //             if((letter >= 48 && letter <= 57) || letter == '.') {
    //                 RHS.push_back(letter);
    //             }
    //             // if((letter < 46 || letter == 47 || letter > 57) && letter != 32) {
    //             //     return ErrorCode::BadCharacter;
    //             // }
    //         }
    //     }

    //     if(badform >= calc::calculations.size() || LHS.empty() == true) {
    //         return ErrorCode::BadFormat;
    //     }
    //     if(badchar >= calc::calculations.size()) {
    //         return ErrorCode::BadCharacter;
    //     }

    //     lhs = std::stod(LHS);
    //     rhs = std::stod(RHS);

    //     if(rhs == 0 && operation == '/') {
    //         return ErrorCode::DivideBy0;
    //     }

    //     // char operation{ '+' };      // example
    //     // double lhs{ 2 };            // example
    //     // double rhs{ 3 };            // example

    //     /* return error code if input cannot be parsed correctly
    //     //return ErrorCodeBadFormat;
    //     // return ErrorCodeBadCharacter;
    //     return ErrorCodeDivideBy0;
    //     return ErrorCodeModuleOfNonIntegerValue;
    //     return ErrorCodeSqrtOfNegativeNumber;
    //     */

    //     // otherwise calculate and return OK
    //     *out = calc::calculations.at(operation)(lhs, rhs);

    //     return ErrorCode::OK;
    return ErrorCode::BadFormat;
}
