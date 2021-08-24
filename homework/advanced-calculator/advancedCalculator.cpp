#include "advancedCalculator.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

double calculateFactorial(double first, double second) {
    if (first == 0 || first == 1) {
        return 1;
    }
    return std::tgamma(first + 1);
}

const std::map<const char, std::function<double(double, double)>> operations {
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    {'%', std::modulus<int>()},
    {'^', [](const auto base, const auto nthPower) { return std::pow(base, nthPower); }},
    {'$', [](const auto base, const auto nthPower) { return std::pow(base, 1.0 / nthPower); }},
    // {'!', calculateFactorial}
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

bool isBadCharacter(std::string input) {
    return std::any_of(input.begin(), 
                       input.end(),
                       [&input](char character) {
                           return !isdigit(character) && !isAllowedOperation(character) && character != '.';
                       });


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

ErrorCode process(std::string input, double* out) {
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    // return ErrorCode::OK;
}
