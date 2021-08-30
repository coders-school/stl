#include "advancedCalculator.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <cctype>
#include <cmath>
#include <numeric>
#include <vector>
#include <functional>

std::map<const char, std::function<double(const double, const double)>> operations {
    { '+', std::plus<double>{} },
    { '-', std::minus<double>{} },
    { '*', std::multiplies<double>{} },
    { '/', std::divides<double>{} },
    { '%', std::modulus<int>{} },
    { '!', [](const auto number, const auto temp = 1) { 
            return number > 0 ? std::tgamma(number + 1) : std::tgamma(-number + 1) * -1; }},
    { '^', [](const auto base, const auto exp) { return std::pow(base, exp); }},
    { '$', [](const auto value, const auto n) { return std::pow(value, 1/n); }}
};
    
std::string allOperations { "+-*/%!^$ " };
double firstValue { };
char operation { };
double secondValue { };
double secondMinus { 1 };
bool oneValue { false };
bool isFactorial { false };

ErrorCode process(std::string input, double* out) {
    auto codeError = validationAllData(input);
    if (codeError == ErrorCode::OK) {
        std::cout.precision(20);
        *out = countingResults(firstValue, operation, secondValue);
        
    }
    return codeError;
}

ErrorCode validationAllData(const std::string & userData) {
    if (std::any_of(cbegin(userData), 
                    cend(userData), 
                    [](const auto & ele){ 
                        return ele != ',' && !std::isdigit(ele) && ele != '.' && std::all_of(cbegin(allOperations), 
                                                                                             cend(allOperations), 
                                                                                             [&](auto sign){ return ele != sign; });})) { 
        return ErrorCode::BadCharacter;
    }
    if (1 < std::count_if(cbegin(userData), 
                          cend(userData), 
                          [](const auto & ele){ return std::any_of(cbegin(allOperations), 
                                                           cend(allOperations), 
                                                           [&](const auto & sign){ return ele == sign && ele != '-' && ele != ' '; });})) {
        return ErrorCode::BadFormat;
    }
    auto startIterator = cbegin(userData);
    if (*startIterator == '-') {
        startIterator++;
    }
    auto first = std::find_if(startIterator, cend(userData), [](const unsigned char & ele){ return !std::isdigit(ele) && ele != '.' && ele != ','; });
    auto betwen = std::find_if(first, cend(userData), [](const auto & ele){ return std::isdigit(ele); });
    auto second = std::find_if(betwen + 1, cend(userData), [](const auto & ele){ return !std::isdigit(ele) && ele != '.' && ele != ','; });
    return generateErrorCode(first, betwen,  second, userData);
}

ErrorCode generateErrorCode(const std::string::const_iterator & first, const std::string::const_iterator & betwen, const std::string::const_iterator & second, const std::string & userData) {
    auto errorCode = factorialValidation(userData);
    if (errorCode != ErrorCode::OK) {
        return errorCode;
    } 
    errorCode = validFirstValue(first, userData);
    if (errorCode != ErrorCode::OK) {
        return errorCode;
    }
    errorCode = validSign(first, betwen);
    if (errorCode != ErrorCode::OK) {
        return errorCode;
    }
    errorCode = validSecondValue(betwen, second, userData);
    if (errorCode != ErrorCode::OK && isFactorial == false) {
        return errorCode;
    }
    createCountingData(first, betwen, second, userData);
    if (isDivideBy0(userData) == true) {
        return ErrorCode::DivideBy0;
    }
    if (isSqrtOfNegativeNumber(userData) == true) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    if (isModuleOfNonIntegerValue(userData) == true) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    return ErrorCode::OK;
}

ErrorCode factorialValidation(const std::string & userData) {
    isFactorial = false;
    if (1 == std::count_if(begin(userData), end(userData), [](const auto & ele){ return std::any_of(begin(allOperations), end(allOperations), [&](auto sign){ return  ele == '!'; });})) {
        isFactorial = true;
        if (*(end(userData) - 1) != '!') {
            return ErrorCode::BadFormat;
        }
    }
    return ErrorCode::OK;
}

bool isDivideBy0(const std::string& userData) {
    if (operation == '/' && static_cast<int>(secondValue == 0)) {
        return true;
    }
    return false;
}

bool isSqrtOfNegativeNumber(const std::string& userData) {
    if (operation == '$' && firstValue < 0) {
        return true;
    }
    return false;
}

bool isModuleOfNonIntegerValue(const std::string& userData) {
    if (operation == '%' && (firstValue != static_cast<int>(firstValue) || secondValue != static_cast<int>(secondValue))) {
        return true;
    }
    return false; 
}

ErrorCode validFirstValue(const std::string::const_iterator& first, const std::string & userData) {
    if (first != begin(userData) && std::isdigit(*first)) {
        return ErrorCode::BadCharacter;
    }
    if (std::count_if(begin(userData), first, [](const auto & ele){ return ele == '.'; }) > 1) {
        return ErrorCode::BadFormat;
    }
    if (std::any_of(begin(userData), end(userData), [](const auto & ele){ return ele == ','; })) {
        return ErrorCode::BadFormat;
    }
    return ErrorCode::OK;
}

ErrorCode validSign(const std::string::const_iterator& itBegin, const std::string::const_iterator& itEnd) {
    secondMinus = 1;
    if (std::any_of(itBegin, itEnd, [](const auto & ele){ return std::all_of(begin(allOperations), end(allOperations), [&](auto sign){ return ele != sign; });})) {
        return ErrorCode::BadFormat;
    }
    if (std::count_if(itBegin, itEnd, [](const auto & ele){ return std::any_of(begin(allOperations), end(allOperations), [&](auto sign){ return ele == sign && ele != ' '; }); }) == 2) {
        secondMinus = -1;
    }
    return ErrorCode::OK;
}

ErrorCode validSecondValue(const std::string::const_iterator& beginIt, const std::string::const_iterator& endIt, const std::string & userData) {
    oneValue = false;
    if (std::any_of(begin(userData), endIt, [](const auto & ele){ return ele == '!';})) {
        return ErrorCode::BadCharacter;
    }
    if(!std::all_of(beginIt, end(userData), [](const auto & ele){ return std::isdigit(ele) || ele == '.';})) {
        return ErrorCode::BadFormat;
    }
    if (endIt != end(userData)) {
        return ErrorCode::BadCharacter;
    }
    if (std::count_if(endIt, end(userData), [](const auto & ele){ return ele == '.'; }) > 1) {
        return ErrorCode::BadFormat;
    }
    if (std::any_of(beginIt, endIt, [](const auto & ele){ return ele == ','; })) {
        return ErrorCode::BadFormat;
    }
    return ErrorCode::OK;
}

void createCountingData(const std::string::const_iterator & first, const std::string::const_iterator & betwen, const std::string::const_iterator & second, const std::string & userData) {
    secondValue = 0;
    std::string tempString {};
    std::copy(begin(userData), first, std::back_inserter(tempString));
    firstValue = std::stod(tempString);
    tempString.clear();
    std::copy(first, betwen + 1, std::back_inserter(tempString));
    tempString.erase(std::remove(begin(tempString), end(tempString), ' '), end(tempString));
    operation = tempString[0];
    if (!isFactorial) {
        tempString.clear();
        std::copy(betwen, end(userData), std::back_inserter(tempString));
        secondValue = std::stod(tempString);
        secondValue *= secondMinus;
    }
}

double countingResults(double first, char oper, double second) {
    auto it = operations.find(oper);
    return it->second(first, second);
}
