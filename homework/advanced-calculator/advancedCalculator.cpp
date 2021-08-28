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
    {'!', [](auto value, [[maybe_unused]] auto unused) { return value <= 0 ? 1.0 : std::tgamma(value + 1.0); }}
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
    if (input.front() != '-' || !isdigit(input.front())) {
        return true;
    }
    if (input.front() == '-' && !isdigit(input[1])) {
        return true;
    }
    size_t minusCount = std::count(input.begin(), input.end(), '-');
    if (minusCount > 3 ) {
        return true;
    }
    size_t dotCount = std::count(input.begin(), input.end(), '.');
    if (dotCount > 2) {
        return true;
    }
    size_t commaCount = std::count(input.begin(), input.end(), ',');
    if (commaCount > 0) {
        return true;
    }
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

double stringToDouble(std::string input) {
    std::stringstream ss;
    ss << input;
    double number{};
    ss >> number;
    return number;
}

Data divideInput(std::string& input) {
  if (input.empty()) {
    return {};
  }
    std::string allowedOperations {"+-*/%^$!"};
    auto it = std::find_first_of (input.begin() + 1,
                                  input.end(),
                                  allowedOperations.begin(), 
                                  allowedOperations.end());
    Data data;
    if (it == input.end()) {
       return {};   
    }
   
    data.operation_ = *it;
    data.firstValue_ = input.substr(0, std::distance(input.begin(), it));
    size_t sizeOfFirstValue = (data.firstValue_).size();
    data.secondValue_ = input.substr(sizeOfFirstValue + 1, std::distance(it+1, input.end()));
    return data;
}

std::string doubleToString(double number) {
    std::ostringstream ss;
    ss << number;
    std::string output = ss.str();
    return output;
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
