#include "advancedCalculator.hpp"
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <regex>

bool isBadCharacter(const std::string& input) {
    std::regex badCharacterChecker("[a-zA-Z@#&()_=;:'\"\?\\\\<>\\[\\]]+");
    if (std::regex_search(input, badCharacterChecker)) {
        return true;
    }

    return false;
}

bool isBadFormat(const std::string& input) {
    std::regex formatChecker("-?[0-9]+(?:\\.[0-9]+)?\\s*([-+*/%^$])\\s*(?:[-]?[0-9]+(?:\\.[0-9]+)?)\\s*|[-]?[0-9]+(?:\\.[0-9]+)?\\s*!\\s*");
    if (!std::regex_match(input, formatChecker)) {
        return true;
    }

    return false;
}

bool isInteger(double value) {
    double absolute = abs(value);
    return absolute == floor(absolute);
}

ErrorCode process(std::string input, double* out) {
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    } else if (isBadFormat(input)) {
        return ErrorCode::BadFormat;
    }

    input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

    size_t pos = 0;
    double lhs = std::stod(input, &pos);
    double rhs = 0;
    const char op = input.at(pos);

    input.erase(input.begin(), input.begin() + pos + 1);

    if (op != '!') {
        rhs = std::stod(input);
    }

    if (op == '%' && !(isInteger(lhs) && isInteger(rhs))) {
        return ErrorCode::ModuleOfNonIntegerValue;
    } else if (op == '/' && rhs == 0) {
        return ErrorCode::DivideBy0;
    } else if (op == '$' && (lhs < 0)) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    std::cout << lhs << " op: " << op << std::endl;

    std::map<char, std::function<double()>> operations;

    operations['+'] = [&lhs, &rhs]() { return lhs + rhs; };
    operations['-'] = [&lhs, &rhs]() { return lhs - rhs; };
    operations['*'] = [&lhs, &rhs]() { return lhs * rhs; };
    operations['/'] = [&lhs, &rhs]() { return lhs / rhs; };
    operations['$'] = [&lhs, &rhs]() { return std::pow(lhs, 1.0 / rhs); };
    operations['^'] = [&lhs, &rhs]() { return std::pow(lhs, rhs); };
    operations['%'] = [&lhs, &rhs]() { return static_cast<int>(lhs) % static_cast<int>(rhs); };
    operations['!'] = [&lhs]() { 
        if(lhs < 0){
            return std::tgamma(std::abs(lhs) + 1) * (-1);
        }else{
            return std::tgamma(std::abs(lhs) + 1);
        } };

    *out = operations.at(op)();

    return ErrorCode::OK;
}