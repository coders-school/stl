#include "advancedCalculator.hpp"
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <sstream>

const std::map<const char, std::function<double(double, double)>> operations {
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    {'%', std::modulus<int>()},
    {'^', [](const auto base, const auto nthPower) { return std::pow(base, nthPower); }},
    {'$', [](const auto base, const auto nthPower) { return std::pow(base, 1.0 / nthPower); }},
    {'!', [](auto value, [[maybe_unused]] auto unused) {if (value >= 0.0) {
             return std::tgamma(value + 1);
         }
         return -std::tgamma(-value + 1);} }
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
                           return !isdigit(character) && !isAllowedOperation(character) && character != '.' && character != ' ' && character != ',' ;
                       });
}

bool isInteger(double number) {
    return std::floor(number) == number;
}

bool isBadFormat(std::string& input, Data& data) {
  
    input.erase(std::remove(begin(input), end(input), ' '), end(input));
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
    const std::string operations{"+*/%^$!"};
    size_t operationCount {0};
    for(int i = 0; i < operations.size(); i++) {
        operationCount += std::count(input.begin(), input.end(), operations[i]);
    }
    if (operationCount > 1) {
      return true;
    }
    if (isBadNumber(data.firstValue_)) {
        return true;
    }

    if (data.operation_ == '!') {
       if (input.size() != data.firstValue_.size() + 1) {
         return true;
       }
    }
    else {
      if (isBadNumber(data.secondValue_)) {
        return true;
      }
    }
    return false;
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
  input.erase(std::remove(begin(input), end(input), ' '), end(input));
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
    if (data.operation_ == '!') {
      data.secondValue_ = "";
    }
    else {
      size_t sizeOfFirstValue = (data.firstValue_).size();
      data.secondValue_ = input.substr(sizeOfFirstValue + 1, std::distance(it+1, input.end()));
    }
    return data;
}

bool isBadNumber(std::string& input) {
    input.erase(std::remove(begin(input), end(input), ' '), end(input));
    if (!(input[0] == '-' || isdigit(input[0]))) {
        return true;
    }
    if (input.front() == '-' && !isdigit(input[1])) {
        return true;
    }
    size_t dotCount = std::count(input.begin(), input.end(), '.');
    if (dotCount > 1) {
        return true;
    }
    size_t minusCount = std::count(input.begin(), input.end(), '-');
    if (minusCount > 1) {
        return true;
    }
    size_t commaCount = std::count(input.begin(), input.end(), ',');
    if (commaCount > 0) {
        return true;
    }
    return false;
}

ErrorCode process(std::string input, double* out) {
    Data data;
    data = divideInput(input);
    
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (isBadFormat(input, data)) {
        return ErrorCode::BadFormat;
    }
    double firstNumber = stringToDouble(data.firstValue_);
    double secondNumber = stringToDouble(data.secondValue_);
    if (data.operation_ == '/' &&  secondNumber == 0) {
        return ErrorCode::DivideBy0;
    }
    if (data.operation_ == '%' && (!isInteger(firstNumber)) || !isInteger(secondNumber)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    if (data.operation_ == '$' && ((firstNumber <= 0) || (secondNumber <= 0))) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    *out = operations.at(data.operation_)(firstNumber, secondNumber);
    return ErrorCode::OK;
}
