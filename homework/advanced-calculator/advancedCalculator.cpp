#include "advancedCalculator.hpp"
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
// #include <string>

bool isValidOperation(char c) {
    return c == '+' ||  c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '$' || c == '!';
}

double calculate(char operation, auto first, auto second) {
    std::map<char, std::function<double(double, double)>> operations {
        {'+', [](double a, double b){return a + b;}},
        {'-', [](double a, double b){return a - b;}},
        {'*', [](double a, double b){return a * b;}},
        {'/', [](double a, double b){return a / b;}},
        {'%', [](int a, int b){return a % b;}},
        {'^', [](double a, double b){return std::pow(a, b);}},
        {'$', [](double a, double b){return std::pow(a, 1/b);}},
        {'!', [](double a, double b){return a < 0 ? -std::tgamma(-a + 1) : std::tgamma(a + 1);}}
    };
    return operations[operation](first, second);
}



ErrorCode process(std::string input, double* out) {

    auto isOperationButNotMinus = [](auto c){ return isValidOperation(c) && c != '-';};

    if (std::any_of(input.begin(), input.end(), [](auto c){return !(isdigit(c) || isValidOperation(c) || isspace(c) || c == '.' || c == ',');}) ) {
        return ErrorCode::BadCharacter;
    }

    int operationCounter = 0;
    int minusCounter = 0;
    int dotCounter = 0;
    for (auto it = input.begin(); it != input.end(); it++) {
        if (isOperationButNotMinus(*it)) {
            ++operationCounter;
        }
        if (*it == '-') {
            ++minusCounter;
        }
        if (*it == '!' && !input.ends_with(*it)) {
            return ErrorCode::BadFormat;
        }
        if (*it == '.') {
            ++dotCounter;
        }
        if (*it == ',') {
            return ErrorCode::BadFormat;
        }
        
    }

    if (isOperationButNotMinus(*input.begin())          // has operation sign at the beginning
        || operationCounter > 1
        || dotCounter > 2
        || minusCounter > 3) {
            return ErrorCode::BadFormat;
    }

    size_t position;
    double firstNumber = std::stod(input, &position);
    input.erase(0, position);
    std::erase_if(input, isspace);
    char operation = input[0];  // wczesniej 1
    input.erase(0, 1); // wczensiej 0, 2
    double secondNumber = 1.0; 
    if (operation != '!') {
        secondNumber = std::stod(input);
    }
    if (operation == '/' && secondNumber == 0.0) {
        return ErrorCode::DivideBy0;
    }
    if (operation == '%' && dotCounter > 0) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    if (operation == '$' && firstNumber < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    // std::map<char, std::function<double(double, double)>> operations {
    //     {'+', [](double a, double b){return a + b;}},
    //     {'-', [](double a, double b){return a - b;}},
    //     {'*', [](double a, double b){return a * b;}},
    //     {'/', [](double a, double b){return a / b;}},
    //     {'%', [](int a, int b){return a % b;}},
    //     {'^', [](double a, double b){return std::pow(a, b);}},
    //     {'$', [](double a, double b){return std::pow(a, 1/b);}},
    //     {'!', [](double a, double b){return a < 0 ? -std::tgamma(-a + 1) : std::tgamma(a + 1);}}

    // };
    // *out = operations[operation](firstNumber, secondNumber);

    // if (operation == '!') {
    //     *out = calculate(operation, firstNumber);
    // } else {
    //     *out = calculate(operation, firstNumber, secondNumber);
    // }

    *out = calculate(operation, firstNumber, secondNumber);

    return ErrorCode::OK;
}