#include "advancedCalculator.hpp"
#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <map>
#include <string>

auto sum = [](double a, double b) -> double {
    return a + b;
};

auto subtract = [](double a, double b) -> double {
    return a - b;
};

std::map<char, std::function<double(double, double)>> operationsMap = {
    {'+', sum}, {'-', subtract}
};

ErrorCode process(std::string input, double* out) {
    Operation operation{};
    ErrorCode errorCode = parse(input, operation);
    std::function<double(double, double)> lambda;
    switch (operation.sign) {
    case '+':
        lambda = operationsMap['+'];
        *out = lambda(operation.a, operation.b);
        return ErrorCode::OK;
    case '-':
        lambda = operationsMap['-'];
        *out = lambda(operation.a, operation.b);
        return ErrorCode::OK;
    }
    // out = nullptr;
    return errorCode;
}

ErrorCode parse(const std::string & string, Operation & operation) {
    std::string stringClean{};
    std::copy_if(cbegin(string),
                 cend(string),
                 std::back_inserter(stringClean),
                 [](auto sign) {
                     return (!isspace(sign));
                 });
    bool containsCharacters = std::any_of(
                cbegin(stringClean),
                cend(stringClean),
                [](auto sign) {
                    return std::isalpha(sign);
                });
    if (containsCharacters) {
        std::cout << "Contains characters!\n";
        return ErrorCode::BadCharacter;
    }
    int indexSign = stringClean.find_first_of("+*/-%!^$");
    int indexNumber = stringClean.find_first_of("1234567890");
    if (indexSign < indexNumber) {
        std::cout << "Bad formatting!\n";
        return ErrorCode::BadFormat;
    }
    operation.a = std::stoi(stringClean.substr(0, indexSign));
    operation.sign = stringClean[indexSign];
    operation.b = std::stoi(stringClean.substr(indexSign + 1));
    
    // std::cout << string << '\n';
    // std::cout << stringClean << '\n';
    // std::cout << "Number A: " << operation.a << '\n';
    // std::cout << "Sign: " << operation.sign << '\n';
    // std::cout << "Number B: " << operation.b << '\n';

    return ErrorCode::Undefined;
}
