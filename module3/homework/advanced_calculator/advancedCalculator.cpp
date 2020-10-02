#include "advancedCalculator.hpp"

#include <algorithm>
#include <cmath>
#include <regex>

double factorial(double num) {
    return std::tgamma(std::abs(num) + 1) * num / std::abs(num);
}

void removeSpaces(std::string& input) {
    input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());
}

std::map<char, std::function<double(double, double)>> operatorsMap{
    {'/', std::divides<double>()},
    {'%', std::modulus<int>()},
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'!', [](auto lhs, auto rhs) { return factorial(lhs); }},
    {'^', [](auto lhs, auto rhs) { return std::pow(lhs, rhs); }},
    {'$', [](auto lhs, auto rhs) { return std::pow(lhs, 1 / rhs); }},
};

bool checkCharacter(const std::string& input) {
    std::string opCode{",.!+/%$-+*^"};
    return std::any_of(input.begin(), input.end(),
                       [&opCode](char letter) {
                           return std::find(opCode.begin(), opCode.end(), letter) == opCode.end() && !isdigit(letter);
                       });
};

ErrorCode extractPattern(std::string& input, std::vector<std::string>* out) {
    removeSpaces(input);
    out->clear();

    const std::regex patternRegex("([-]?\\d+\\.?\\d*)([-+*\\/^$%])?([-]?\\d+\\.?\\d*)?$");
    const std::regex patternFactorial("([-]?\\d+\\.?\\d*)([!])?");
    std::smatch match;

    if (checkCharacter(input)) {
        return ErrorCode::BadCharacter;
    }

    if (std::regex_search(input, match, patternRegex)) {
        if (match[0] != input) {
            return ErrorCode::BadFormat;
        }

        out->emplace_back(match[1]);
        out->emplace_back(match[2]);
        out->emplace_back(match[3]);
        return ErrorCode::OK;
    } else if (std::regex_search(input, match, patternFactorial)) {
        if (match[0] != input) {
            return ErrorCode::BadFormat;
        }

        out->emplace_back(match[1]);
        out->emplace_back(match[2]);
        return ErrorCode::OK;
    }
    return ErrorCode::BadFormat;
}

ErrorCode checkOperatorCode(const double& firstNum, const double& secondNum, const char& op) {
    switch (op) {
    case '$': {
        if (firstNum < 0) {
            return ErrorCode::SqrtOfNegativeNumber;
        }
        return ErrorCode::OK;
    }
    case '^':
    case '!':
    case '*':
    case '-':
    case '+':
        return ErrorCode::OK;
    case '%': {
        if (ceil(firstNum) != floor(firstNum) || ceil(secondNum) != floor(secondNum)) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }
        return ErrorCode::OK;
    }
    case '/': {
        if (secondNum != 0) {
            return ErrorCode::OK;
        }
        return ErrorCode::DivideBy0;
    }
    }
    return ErrorCode::BadCharacter;
}

ErrorCode process(std::string input, double* out) {
    std::vector<std::string> vec;
    double firstNum = 0, secondNum = 0;
    char op;

    auto errorCode = extractPattern(input, &vec);

    if (errorCode != ErrorCode::OK) {
        return errorCode;
    }

    firstNum = std::stod(vec[0]);
    op = vec[1][0];
    if (op != '!') {
        secondNum = std::stod(vec[2]);
    }

    errorCode = checkOperatorCode(firstNum, secondNum, op);

    if (errorCode != ErrorCode::OK) {
        return errorCode;
    }

    *out = operatorsMap[op](firstNum, secondNum);
    return ErrorCode::OK;
}
