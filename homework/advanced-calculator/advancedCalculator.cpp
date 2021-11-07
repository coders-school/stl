#include "advancedCalculator.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <string>

std::string operationSigns = "+*/-%!^$";
std::string digits = "1234567890";

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
    bool containsAlphabeticCharacters = std::any_of(
                cbegin(stringClean),
                cend(stringClean),
                [](auto sign) {
                    return std::isalpha(sign);
                });
    if (containsAlphabeticCharacters) {
        return ErrorCode::BadCharacter;
    }

    bool containsComma = std::any_of(
                cbegin(stringClean),
                cend(stringClean),
                [](auto sign) {
                    return sign == ',';
                });
    if (containsComma) {
        return ErrorCode::BadFormat;
    }

    auto indexFirstNumber = stringClean.find_first_of(digits);
    auto indexFirstSign = stringClean.find_first_of(operationSigns);
    auto indexOperationSign{std::string::npos};
    if (indexFirstSign < indexFirstNumber) {
        if (stringClean[indexFirstSign] != '-') {
            return ErrorCode::BadFormat;
            std::cout << "Wrong operation sign in beginning detected\n";
        } else {
            indexOperationSign = stringClean.find_first_of(operationSigns, indexFirstSign + 1);
        }
    } else {
        indexOperationSign = indexFirstSign;
    }
    std::cout << "Operation sign:" << stringClean[indexOperationSign] << "\n";

    auto indexSecondNumber = stringClean.find_first_of(digits, indexOperationSign + 1);
    auto indexFurtherSign = stringClean.find_first_of(operationSigns, indexOperationSign + 1);

    // if ((indexFurtherSign != std::string::npos) || (!((indexFurtherSign < indexSecondNumber) && (stringClean[indexFurtherSign] == '-')))) {
    //     std::cout << "Second operation sign detected\n";
    //     return ErrorCode::BadFormat;
    // }

    // if ((indexFurtherSign != std::string::npos)) {
    //     std::cout << "Second operation sign detected\n";
    //     std::cout << "Further operation sign:" << stringClean[indexFurtherSign] << "\n";
    //     return ErrorCode::BadFormat;
    // }

    if ((indexFurtherSign != std::string::npos)) {
        std::cout << "Second operation sign detected\n";
        if (!(indexFurtherSign < indexSecondNumber) && (stringClean[indexFurtherSign] == '-')) {
            return ErrorCode::BadFormat;
        }
    }

    operation.a = std::stod(stringClean.substr(0, indexOperationSign));
    operation.sign = stringClean[indexOperationSign];
    if (operation.sign != '!') {
        operation.b = std::stod(stringClean.substr(indexOperationSign + 1));
    } else {
        operation.b = 0;
    }

    return ErrorCode::OK;
}
