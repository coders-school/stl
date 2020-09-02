#include "advancedCalculator.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <functional>
#include <map>

#include <iostream>

std::function<int(int)> factorial;
/*factorial = [&factorial](int n)
{ return n < 2 ? 1 : n * factorial(n - 1); };*/

const std::map<char, std::function<double(double, double)>> equation {
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    //{'!',  },
    {'^', [](double base, double exp) { return std::pow(base, exp); } },
    {'$', [](double base, double exp) { return std::pow(base, 1/exp); } }
};

ErrorCode process(std::string operation, double* result) {
    if (std::any_of(operation.cbegin(), operation.cend(), isalpha)) {
        return ErrorCode::BadCharacter;
    }
    const std::string forbiddenChar = "=[]@#&();?\\";
    for (const auto& it : forbiddenChar) {
        if (std::any_of(operation.cbegin(), operation.cend(), [&it](const char& c){ return it == c; } )) {
            return ErrorCode::BadCharacter;
        }
    }
    if (std::any_of(operation.cbegin(), operation.cend(), [](const char& c){ return c == ','; } )) {
        return ErrorCode::BadFormat;
    }
    
    //std::cout << "-----------------------" << operation << '\n';
    operation.erase(remove_if(operation.begin(), operation.end(), isspace), operation.end());


    return ErrorCode::OK;
}