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
bool isBadFormat(std::string& input) {
    input.erase(std::remove(begin(input), end(input), ' '), end(input));
    Data data = parseString(input);
    if (input != std::to_string(data.firstValue_) +
                 std::to_string(data.operation_) +
                 std::to_string(data.secondValue_)) {
        return true;
    }
    return false;
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

Data parseString(std::string& input) {
    Data data;
    data.firstValue_ = std::stod(input);
    std::string allowedOperations {"+-*/%^$!"};
    auto it = std::find_first_of(input.begin(),
                                input.end(),
                                allowedOperations.begin(), 
                                allowedOperations.end());
    data.operation_ = *it;
    input.erase(begin(input), it + 1);
    data.secondValue_ = std::stod(input);
    return data;
}

ErrorCode process(std::string input, double* out) {
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (isBadFormat(input)) {
        return ErrorCode::BadFormat;
    }
    // return ErrorCode::OK;
}
