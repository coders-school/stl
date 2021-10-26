#include "advancedCalculator.hpp"
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>

double calculate(const char& operation, const auto& first, const auto& second) {
    std::map<char, std::function<double(double, double)>> operations {
        {'+', [](const double& a, const double b){return a + b;}},
        {'-', [](const double a, const double& b){return a - b;}},
        {'*', [](const double& a, const double& b){return a * b;}},
        {'/', [](const double& a, const double& b){return a / b;}},
        {'%', [](const int& a, const int& b){return a % b;}},
        {'^', [](const double& a, const double& b){return std::pow(a, b);}},
        {'$', [](const double& a, const double& b){return std::pow(a, 1/b);}},
        {'!', [](const double& a, const double& b){return a < 0 ? -std::tgamma(-a + 1) : std::tgamma(a + 1);}}
    };
    return operations[operation](first, second);
}

bool isOperationButNotMinus(const char& c) {
    return c == '+' || c == '*' || c == '/' || c == '%' || c == '^' || c == '$' || c == '!';
}

ErrorCode process(std::string input, double* out) {
    if (std::any_of(input.cbegin(),
                    input.cend(),
                    [](auto c){ return !(isdigit(c)
                                       || isOperationButNotMinus(c)
                                       || c == '-'
                                       || isspace(c)
                                       || c == '.'
                                       || c == ',');})) {
        return ErrorCode::BadCharacter;
    }
    
    int operationCounter = 0;
    int minusCounter = 0;
    int dotCounter = 0;
    for (auto it = input.cbegin(); it != input.cend(); it++) {
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
    if (isOperationButNotMinus(*input.cbegin())
        || operationCounter > 1
        || dotCounter > 2
        || minusCounter > 3) {
            return ErrorCode::BadFormat;
    }

    size_t position;
    double firstNumber = std::stod(input, &position);
    input.erase(0, position);
    std::erase_if(input, isspace);
    char operation = input[0];
    input.erase(0, 1);
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

    *out = calculate(operation, firstNumber, secondNumber);
    return ErrorCode::OK;
}
