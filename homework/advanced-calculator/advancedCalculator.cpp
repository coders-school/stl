#include "advancedCalculator.hpp"
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <sstream>
// #include <strstream>

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
    std::string firstNumber = doubleToString(data.firstValue_);
    std::string secondNumber = doubleToString(data.secondValue_);
    if (data.operation_ == '!') {
        if (input != (firstNumber + data.operation_)) {
            return true;
        }
    }
    else if (input != (firstNumber + data.operation_ + secondNumber)) {
        return true;
    }
    return false;
}

// void breaksStringToMembers (std::string input) {
//     std::string allowedOperations {"+-*/%^$!"};
//     for (auto& el : input) {
//         auto it = std::find_if (input.begin(),
//                                 input.end(),
//                                 [allowedOperations](auto el){
//                                     for (auto& allowed : allowedOperations) {
//                                         return el == allowed;
//                                     } 
//                                 });
//         //return it;
//     }
// }

size_t getPrecision(std::string input) {
    auto is_significant = [](auto c) {
        return std::isdigit(c);
    };
    auto found = std::find(begin(input), end(input), '.');
    auto first = std::find_if(found, end(input), is_significant);
    auto last  = std::find_if(rbegin(input), rend(input), is_significant).base();
    return std::count_if(first, last, [](auto c) {
        return std::isdigit(c);
    });
}

double stringToDoubleWithPrecision(std::string input, size_t precision) {
    std::stringstream ss;
    ss << std::setprecision(precision) << std::fixed << input;
    double number{};
    ss >> number;
    return number;
}

std::string doubleToString(double number) {
    std::ostringstream ss;
    ss << number;
    std::string output = ss.str();
    return output;
}

Data parseString(std::string input) {
    Data data;
    size_t precision = getPrecision(input);
    data.firstValue_ = stringToDoubleWithPrecision(input, precision);
    std::string allowedOperations {"+-*/%^$!"};
    auto it = std::find_first_of(input.begin(),
                                input.end(),
                                allowedOperations.begin(), 
                                allowedOperations.end());
    data.operation_ = *it;
    if (data.operation_ == '!') {
        return data;
    }
    input.erase(begin(input), it + 1);
    precision = getPrecision(input);
    data.secondValue_ = stringToDoubleWithPrecision(input, precision);
    return data;
}

ErrorCode process(std::string input, double* out) {
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (isBadFormat(input)) {
        return ErrorCode::BadFormat;
    }
    return ErrorCode::OK;
}
