#include "advancedCalculator.hpp"

#include <functional>
#include <map>
#include <cmath>
#include <iostream>

const std::map<char, std::function<double(double,double)>> operations {
    {'+', std::plus<>()},
    {'-', std::minus<>()},
    {'*', std::multiplies<>()},
    {'/', std::divides<>()},
    {'%', std::modulus<int>()},
    {'^', [](auto base, auto exponent){ return pow(base, exponent); }},
    {'$', [](auto value, auto root){ return pow(value, 1.0 / root); }},
    {'!', [](auto value, auto notUsed){ return value <=0 ? 1.0 : std::tgamma(value + 1.0); }}
};

ErrorCode process(const std::string& input, double* result)
{
    char operation;


    auto lhs = 7;
    auto rhs = 3;

    if ((operation == '/') and (rhs == 0)) {
        return ErrorCode::DivideBy0;
    } else if ((operation == '$') and (lhs < 0)) {
        return ErrorCode::SqrtOfNagativeNumber;
    }
    else if (auto it = operations.find(operation); it != operations.end()) {
        *result = it->second(lhs, rhs);
        return ErrorCode::OK;
    } else {
        return ErrorCode::BadCharacter;
    }
}
