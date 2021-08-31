#include "advancedCalculator.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <vector>

// double result = 0;
std::string allowedChars = { "+-/*%!^$" };

ErrorCode process(std::string input, double* out) {
    input.erase(std::remove(begin(input), end(input), ' '), end(input));
    if (validateCharacters(input)) {
        return ErrorCode::BadCharacter;
    }
    if (!validateFormat(input)) {
        return ErrorCode::BadFormat;
    }
    char operation = findCommand(input, allowedChars);

    auto it = std::find_first_of(input.begin() + 1,
                                 input.end(),
                                 allowedChars.begin(),
                                 allowedChars.end());
    std::string::size_type sz;
    double lhs = std::stod(input, &sz);
    double rhs;
    if (operation == '!') {
        rhs == 0;
    }
    else {
        rhs = std::stod(input.substr(sz+1));
    }
    

    switch (operation) {
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
            if (lhs < 0) {
                return ErrorCode::SqrtOfNegativeNumber;
            }
            *out = commands.find('$')->second(lhs, rhs);
            std::cout << *out;
            return ErrorCode::OK;
            break;
    }

}

bool isAllowedChar (char c) {
    return std::find_if(allowedChars.begin(), allowedChars.end(), [&c](char allowed){ return c == allowed; }) != allowedChars.end();
}

bool validateCharacters (const std::string & input) {
    return std::any_of(input.begin(), input.end(), [](char c){ return !isdigit(c) && !isAllowedChar(c) && c != ' ' && c != '.'; }); 
}


bool validateFormat (std::string &input) {
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

