#include "advancedCalculator.hpp"
#include <algorithm>
#include <iostream>
#include <functional>
#include <map>
#include <vector>

std::string allowedChars = { "+-/*%!^$" };

ErrorCode process(std::string input, double* out) {
    input.erase(std::remove(begin(input), end(input), ' '), end(input));
    if (validateCharacters(input)) {
        return ErrorCode::BadCharacter;
    }
    if (!validateFormat(input)) {
        return ErrorCode::BadFormat;
    }

    char symbol = findCommand(input, allowedChars);
    
    std::string::size_type sz;
    double lhs = parseLhs(input, sz);
    double rhs = parseRhs(input, sz, symbol);

    switch (symbol) {
        case '+':
            *out = commands.find('+')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '-':
            *out = commands.find('-')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '*':
            *out = commands.find('*')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '/':
            if (lhs == 0 || rhs == 0) {
                return ErrorCode::DivideBy0;
            }
            *out = commands.find('/')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '%':
            if (!isInteger(lhs) || !isInteger(rhs)){
                return ErrorCode::ModuleOfNonIntegerValue;
            }
            *out = commands.find('%')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '!':
            *out = commands.find('!')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '^':
            *out = commands.find('^')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '$':
            if (lhs <= 0 || rhs == 0) {
                return ErrorCode::SqrtOfNegativeNumber;
            }
            *out = commands.find('$')->second(lhs, rhs);
            std::cout << *out;
            return ErrorCode::OK;
            break;
        default:
            return ErrorCode::Undefined;
            break;
    }
}

bool isAllowedChar (char c) {
    return std::find_if(allowedChars.begin(), allowedChars.end(), [&c](char allowed){ return c == allowed; }) != allowedChars.end();
}

bool validateCharacters (const std::string & input) {
    return std::any_of(input.begin(),
                       input.end(), 
                       [](char c){ return !isdigit(c) && !isAllowedChar(c) && c != ' ' && c != '.' && c != ','; }); 
}

bool validateFormat (std::string &input) {

        if (std::count(begin(input), end(input), ',') > 0) {
            return false;
        }
        if (std::count (begin(input), end(input), '-') > 3) {
            return false;
        }
        if (std::count_if(input.begin() + 1, input.end(), [](char c){ return checkFormatSymbols(c) ; }) > 1) {
            return false;
        }
        if (*begin(input) == '+') {
            return false;
        }
        if (std::count (begin(input), end(input), '.') > 2) {
            return false;
        }
        if (findCommand(input, allowedChars) == '!') {
            auto it = std::find(input.begin(), input.end(), '!');
            if (it + 1 != input.end()) {
                return false;
            }
        }
        return true;

}

char findCommand (std::string &input, std::string &allowedChars) {
    char command;
    auto it = std::find_first_of(input.begin() + 1,
                                 input.end(),
                                 allowedChars.begin(),
                                 allowedChars.end());
    return command = *it;
}

double parseLhs (std::string &input, std::string::size_type &sz) {
    return std::stod(input, &sz);
}

double parseRhs (std::string &input, std::string::size_type &sz, char &symbol) {
    double rhs;
    if (symbol == '!') {
        return rhs = 0;
    }
    return rhs = std::stod(input.substr(sz+1));
}

bool checkFormatSymbols (char &c) {
    std::string symbolsToCheck = "+/*%!^$";
    return std::find_if(symbolsToCheck.begin(), symbolsToCheck.end(), [&c](char symbol){ return c == symbol; }) != symbolsToCheck.end();
}

bool isInteger (double num) {
    return std::floor(num) == num;
}