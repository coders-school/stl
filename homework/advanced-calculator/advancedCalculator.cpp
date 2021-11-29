#include "advancedCalculator.hpp"
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <iterator>
#include <cmath>

#include <iostream>

auto returnOperation(std::string & str1) {
    for(auto it = str1.begin(); it != str1.end(); ++it) {
        if((((*it == '+') || (*it == '-') || (*it == '*') || (*it == '/') || (*it == '^') || (*it == '%') || (*it == '$') || (*it == '!')) && (it != str1.begin()))) {
        return it;
        }
    }
    return str1.end();
}

bool checkOperation(const std::string & str1) {
    for(auto it = str1.begin(); it != str1.end(); ++it) {
        if((((*it == '+') || (*it == '-') || (*it == '*') || (*it == '/') || (*it == '^') || (*it == '%') || (*it == '$') || (*it == '!')) && (it != str1.begin()))) {
        return true;
        }
    }
    return false;
}

bool isNumber(const std::string & str2) {
    for (auto it = str2.begin(); it != str2.end();++it){
        if (!std::isdigit(*it) && (*it != '.') && (*it != '-')) {
            return false;
        }
    }
    return true;
}

bool checkInputFormat(const std::string & str3, const char & c, const std::string & nFirst, const std::string & nSecond) {
    int operationCounter = 0;
    int minusCounter = 0;
    int duplicateOperation = 0;
    for (auto it = str3.begin(); it != str3.end(); ++it) {
        if (*it == ',') {
            return false;
        }
        if (it == str3.begin() && !isdigit(*it) && *it != '-') {
            return false;
        }
        if (*it == c && *std::next(it) == c && *std::next(it) != '-') {
            return false;
        }
        // if((*it == '+') || (*it == '-') || (*it == '*') || (*it == '/') || (*it == '^') || (*it == '%') || (*it == '$') || (*it == '!')) {
        //     ++operationCounter;
        // }
    }
    // if (operationCounter > 3) {
    //     return false;
    // }
    return true;
}

bool isInteger(const std::string & str4) {
    for (auto it = str4.begin(); it != str4.end(); ++it) {
        if (*it == '.') {
            return false;
        }
    }
    return true;
}

double doMath (const char & c,const auto & first,const auto & second) {
    std::map<char, std::function<double(double, double)>> mathMap {
        {'+', [](const double & x, const double & y){ return x + y;}},
        {'-', [](const double & x, const double & y){ return x - y;}},
        {'*', [](const double & x, const double & y){ return x * y;}},
        {'/', [](const double & x, const double & y){ return x / y;}},
        {'^', [](const double & x, const double & y){ return pow(x, y);}},
        {'$', [](const double & x, const double & y){ return pow(x, 1/y);}},
        {'%', [](const int & x, const int & y){ return x % y;}},
        {'!', [](const double & x, const double & y){ 
                                                if (x >=0) {
                                                    return std::tgamma(x+1);
                                                }
                                                return -std::tgamma(-x+1);
                                                }}
    };
    return mathMap[c](first, second);
}

ErrorCode process(std::string input, double * out) {
    std::string first;
    std::string second;

    auto isSpace = [](unsigned char x){ return std::isspace(x);};
    auto operation = returnOperation(input);
    std::remove_copy_if(input.begin(), operation, std::back_inserter(first),isSpace);
    std::remove_copy_if(std::next(operation), input.end(), std::back_inserter(second),isSpace);
    std::cout << second << '\n';
    if (!checkInputFormat(input, *operation, first, second)){
        return ErrorCode::BadFormat;
    }
    if(!isNumber(first) || !isNumber(second)){
        return ErrorCode::BadCharacter;
    }
    if((*operation == '/') && (std::stod(second) == 0)) {
        return ErrorCode::DivideBy0;
    }
    if((*operation == '$') && (std::stod(first) < 0)) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    if((*operation == '%') && (!isInteger(first) || !isInteger(second))) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    if(*operation == '!') {
        second = "0.0";
    }

    *out = doMath(*operation,std::stod(first),std::stod(second));    
    return ErrorCode::OK;
}