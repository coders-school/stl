#include "advancedCalculator.hpp"
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <cmath>

bool checkOperation(const char & operation) {
    if(operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^' || operation == '%' || operation == '$' || operation == '!') {
        return true;
    }
    return false;
}

auto returnOperation(std::string & str1) {
    for(auto it = str1.begin(); it != str1.end(); ++it) {
        if(checkOperation(*it) && (it != str1.begin())) {
            return it;
        }
    }
    return str1.end() - 1;
}

bool checkCharacter (const std::string & str2) {
    if (std::any_of(str2.begin(), str2.end(), [](const auto & c){
        return !checkOperation(c) && !isdigit(c) && !isspace(c) && c != '.' && c != ',';
        })) {
            return true;
        }
    return false;
}

bool isNumber(const std::string & str3) {
    int dotCounter = 0;
    for (auto it = str3.begin(); it != str3.end();++it){
        if (checkOperation(*it) && *it != '-') {
            return false;
        }
        if (*it == ',') {
            return false;
        }
        if (*it == '.') {
            ++dotCounter;
            if(dotCounter > 1) {
                return false;
            }
        }
    }
    return true;
}

bool checkFormat(const char & c, const std::string & firstNum, const std::string & secondNum) {
    if (c == '!' && secondNum !="") {
        return false;
    }
    if(!isNumber(firstNum) || !isNumber(secondNum)) {
        return false;
    }
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

double doMath (const char & c,const double & first,const double & second) {
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
    std::string first ="";
    std::string second ="";

    auto isSpace = [](unsigned char x){ return std::isspace(x);};
    auto operation = returnOperation(input);
    std::remove_copy_if(input.begin(), operation, std::back_inserter(first),isSpace);
    std::remove_copy_if(std::next(operation), input.end(), std::back_inserter(second),isSpace);

    if (checkCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (!checkFormat(*operation, first, second)){
        return ErrorCode::BadFormat;
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