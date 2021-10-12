#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <iterator>
#include <map>
#include <regex>
#include <sstream>
#include <vector>

std::map<char, std::function<double(double, double)>> calcOperations{
    {'+', std::plus<>()},
    {'-', std::minus<>()},
    {'*', std::multiplies<>()},
    {'/', std::divides<>()},
    {'%', std::modulus<int>()},
    {'^', [](auto base, auto exponent) { return std::pow(base, exponent); }},
    {'$', [](auto base, auto root) { return std::pow(base, 1.0 / root); }},
    {'!', [](auto value, [[maybe_unused]] auto unused) { return value < 0
                                                       ? -std::tgamma(-value + 1.0)
                                                       : std::tgamma(value + 1.0); }
    }
};

bool isInteger(double number) {
    return std::floor(number) == number;
}

bool isBadCharacter(const std::string& input) {
    const std::array<char, 21> legalCharacters{'+', '-', '*', '/', '%', '!', '^', '$', '.', ',',
                                               '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '};
    return std::any_of(input.begin(),
                       input.end(),
                       [legalCharacters](char character) {
                           return std::find(legalCharacters.begin(),
                                            legalCharacters.end(),
                                            character) == legalCharacters.end();
                       });
}

ErrorCode process(const std::string& input, double* const out) {
    if (isBadCharacter(input)) {
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
        *out = calcOperations.at(operation[0])(lhs, rhs);
        return ErrorCode::OK;
    }
    return ErrorCode::BadFormat;
}
