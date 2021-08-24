#include "advancedCalculator.hpp"

#include <algorithm>
#include <cctype>
#include <math.h>
#include <numeric>
#include <vector>

std::map<const char, std::function<double(const double, const double)>> operations;

ErrorCode process(std::string input, double* out) {
    operationsInit();
    auto codeError = validationUserData(input);
    if (codeError == ErrorCode::OK) {
        *out = coutingResults(getFirsValue(input), getSign(input), getSecondValue(input));
    }
    return codeError;
}

void operationsInit() {
    operations.insert(std::make_pair('+', std::plus<double>()));
    operations.insert(std::make_pair('-', std::minus<double>()));
    operations.insert(std::make_pair('*', std::multiplies<double>()));
    operations.insert(std::make_pair('/', std::divides<double>()));
    operations.insert(std::make_pair('%', std::modulus<int>()));
    operations.insert(std::make_pair('!', [counter = 0]
                                          (int ele, int ele2) mutable 
                                          { std::vector<int>fact(ele, ++counter);
                                            return std::accumulate(begin(fact), end(fact), 1, std::multiplies<int>());
                                          }));
    operations.insert(std::make_pair('^', [](auto variable, auto n){ return std::pow(variable, n); }));
    operations.insert(std::make_pair('$', [](auto variable, auto n){ return std::pow(variable, (1/n)); }));
}

ErrorCode validationUserData(const std::string& userData) {
    std::string procesedData = userData;
    if (isBadCharacter(procesedData) == true) {
        return ErrorCode::BadCharacter;
    } 
    if (isBadFormat(procesedData) == true) {
        return ErrorCode::BadFormat;
    }
    if (isBadFormat(procesedData) == true) {
        return ErrorCode::DivideBy0;
    }
    if (isSqrtOfNegativeNumber(procesedData) == true) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    if (isModuleOfNonIntegerValue(procesedData) == true) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    return ErrorCode::OK;
} 

bool isBadCharacter(const std::string& UserData) {
    //TO DO
    return true;
}

bool isBadFormat(const std::string& UserData) {
    //TO DO
    return true;
}

bool isDivideBy0(const std::string& UserData) {
    //TO DO
    return true;
}

bool isSqrtOfNegativeNumber(const std::string& UserData) {
    //TO DO
    return true;
}

bool isModuleOfNonIntegerValue(const std::string& UserData) {
    //TO DO
    return true; 
}

double getFirsValue(const std::string& UserData) {
    //TO DO
    return 0;
}

char getSign(const std::string& UserData) {
    //TO DO
    return '+';
}

double getSecondValue(const std::string& UserData) {
    //TO DO
    return 0;
}

double coutingResults(double firstValue, char operation, double secondValue) {
    //TO DO
    return 0;
}