#include "advancedCalculator.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <string>

auto add = [](double a, double b) -> double {
    return a + b;
};

auto subtract = [](double a, double b) -> double {
    return a - b;
};

auto multiply = [](double a, double b) -> double {
    return a * b;
};

auto divide = [](double a, double b) -> double {
    return a / b;
};

auto modulo = [](double a, double b) -> double {
    return int(a) % int(b);
};

auto power = [](double a, double b) -> double {
    return std::pow(a, b);
};

auto root = [](double a, double b) -> double {
    return std::pow(a, 1 / b);
};

auto factorial = [](double a, double b) -> double {
    if (a >= 0) {
        return tgamma(a + 1);
    } else {
        return - tgamma(- a + 1);
    }
};

std::map<char, std::function<double(double, double)>> operationsMap = {
    {'+', add},
    {'-', subtract},
    {'*', multiply},
    {'/', divide},
    {'%', modulo},
    {'^', power},
    {'$', root},
    {'!', factorial}
};

ErrorCode process(const std::string & input, double* out) {
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
    case '*':
        lambda = operationsMap['*'];
        *out = lambda(operation.a, operation.b);
        return ErrorCode::OK;
    case '/':
        lambda = operationsMap['/'];
        *out = lambda(operation.a, operation.b);
        return ErrorCode::OK;
    case '%':
        lambda = operationsMap['%'];
        *out = lambda(operation.a, operation.b);
        return ErrorCode::OK;
    case '^':
        lambda = operationsMap['^'];
        *out = lambda(operation.a, operation.b);
        return ErrorCode::OK;
    case '$':
        lambda = operationsMap['$'];
        *out = lambda(operation.a, operation.b);
        return ErrorCode::OK;
    case '!':
        lambda = operationsMap['!'];
        *out = lambda(operation.a, operation.b);
        return ErrorCode::OK;
    }
    // out = nullptr;
    return errorCode;
}

ErrorCode parse(const std::string & string, Operation & operation) {
    std::string stringClean{};  // string without spaces
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
        std::cout << "Contains wrong characters!\n";
        return ErrorCode::BadCharacter;
    }
    int indexSign = stringClean.find_first_of("+*/-%!^$");
    int indexNumber = stringClean.find_first_of("1234567890");
    if (indexSign < indexNumber) {
        if (stringClean[indexSign] != '-') {
            std::cout << "Bad formatting!\n";
            return ErrorCode::BadFormat;
        }
        else {
            indexSign = stringClean.find_first_of("+*/-%!^$", indexSign + 1);
        }
    }

    // TO DO: disallow operator at the end if other than '!'

    operation.a = std::stod(stringClean.substr(0, indexSign));
    operation.sign = stringClean[indexSign];
    if (operation.sign != '!') {
        operation.b = std::stod(stringClean.substr(indexSign + 1));
    } else {
        operation.b = 0;
    }

    // std::cout << string << '\n';
    // std::cout << stringClean << '\n';
    // std::cout << "Number A: " << operation.a << '\n';
    // std::cout << "Sign: " << operation.sign << '\n';
    // std::cout << "Number B: " << operation.b << '\n';

    return ErrorCode::OK;
}
