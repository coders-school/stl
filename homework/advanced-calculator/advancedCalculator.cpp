#include "advancedCalculator.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

const std::map<const char, std::function<double(double, double)>> operations {
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    {'%', std::modulus<int>()},
    {'^', [](const auto base, const auto nthPower) { return std::pow(base, nthPower); }},
    {'$', [](const auto base, const auto nthPower) { return std::pow(base, 1.0 / nthPower); }},
    {'!', [](auto value, auto zero) { return value <= 0 ? 1.0 : std::tgamma(value + 1.0); }}
};

bool isAllowedOperation(char operation) {
    std::string allowedOperations {"+-*/%^$!"};
    auto it = std::find_if(allowedOperations.begin(), 
                           allowedOperations.end(),
                           [&operation](auto el) {
                               return el == operation;
                           });
    return it != allowedOperations.end();
}

bool isBadCharacter(const std::string& input) {
    return std::any_of(input.begin(), 
                       input.end(),
                       [&input](char character) {
                           return !isdigit(character) && !isAllowedOperation(character) && character != '.';
                       });
}

// FINISH
bool isGoodFormat(const std::string& input) {
    if (input[0] != '-' || !isdigit(input[0])) {
        return false;
    }
}

void breaksStringToMembers (std::string input) {
    std::string allowedOperations {"+-*/%^$!"};
    for (auto& el : input) {
        auto it = std::find_if (input.begin(),
                                input.end(),
                                [allowedOperations](auto el){
                                    for (auto& allowed : allowedOperations) {
                                        return el == allowed;
                                    } 
                                });
        //return it;
    }
}

std::tuple<double, char, double> parseString(std::string& input) {
    double firstValue = std::stod(input);
    std::string allowedOperations {"+-*/%^$!"};
    auto it = std::find_first_of(input.begin(),
                                input.end(),
                                allowedOperations.begin(), 
                                allowedOperations.end());
    double secondValue = *it;
    char operation{};
}

ErrorCode process(std::string input, double* out) {
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (!isGoodFormat(input)) {
        return ErrorCode::BadFormat;
    }
    // return ErrorCode::OK;
}
