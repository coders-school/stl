#include "advancedCalculator.hpp"
#include <algorithm>
#include <iostream>

const std::map<char, std::function<double(double, double)>> commands {
    {'+', std::plus<double>{} },
    {'-', std::minus<double>{} },
    {'/', std::divides<double>{} },
    {'*', std::multiplies<double>{} },
    {'%', [](auto lhs, auto rhs){ return (int)lhs % (int)rhs; } },
    //{'%', std::modulus<int>()},
    {'!', [](auto lhs, auto rhs){ return lhs > 0 ? std::tgamma(lhs + 1) : std::tgamma(-lhs + 1)*-1; } },
    {'^', [](auto lhs, auto rhs){ return std::pow(lhs, rhs); } },
    {'$', [](auto lhs, auto rhs){ return std::pow(lhs, 1.0/rhs); } }
};

std::string allowedChars = { "+-/*%!^$" };

ErrorCode process(std::string input, double* out) {
    input.erase(std::remove(begin(input), end(input), ' '), end(input));
    char operation = findCommand(input, allowedChars);
    
    std::string::size_type offset;
    double lhs = parseLhs(input, offset);
    std::cout<<lhs<<'\n';
    double rhs = parseRhs(input, offset, operation);
    std::cout<<rhs<<'\n';
    
    if (validateCharacters(input)) {
        return ErrorCode::BadCharacter;
    }
    if (!validateFormat(input)) {
        return ErrorCode::BadFormat;
    }

    if ((!isInteger(lhs) || !isInteger(rhs)) && operation == '%'){
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    if (rhs == 0 && operation == '/') {
        return ErrorCode::DivideBy0;
    }
    if (lhs <= 0 && operation == '$') {
        return ErrorCode::SqrtOfNegativeNumber;
        }

    *out = commands.at(operation)(lhs,rhs);

    return ErrorCode::OK;    
    
}

char findCommand (std::string &input, std::string &allowedChars) {
    char command;
    auto it = std::find_first_of(input.begin() + 1,
                                 input.end(),
                                 allowedChars.begin(),
                                 allowedChars.end());
    return command = *it;
}

double parseLhs (std::string &input, std::string::size_type &offset) {
    return std::stod(input, &offset);
}

double parseRhs (std::string &input, std::string::size_type &offset, char &symbol) {
    double rhs;
    if (symbol == '!') {
        return rhs = 0;
    }
    return rhs = std::stod(input.substr(offset+1));
}

bool isInteger (double num) {
    return std::floor(num) == num;
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
        if (std::count(begin(input), end(input), '-') > 3) {
            return false;
        }
        if (std::count_if(input.begin() + 1, input.end(), [](char c){ return moreThanOperator(c) ; }) > 1) {
            return false;
        }
        if (*input.begin() == '+') {
            return false;
        }
        if (std::count(begin(input), end(input), '.') > 2) {
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



bool moreThanOperator (char &c) {
    std::string symbolsToCheck = "+/*%!^$";
    return std::find_if(symbolsToCheck.begin(), symbolsToCheck.end(), [&c](char symbol){ return c == symbol; }) != symbolsToCheck.end();
}
