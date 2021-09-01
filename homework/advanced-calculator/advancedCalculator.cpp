#include "advancedCalculator.hpp"
#include <algorithm>

std::string allowedChars = { "+-/*%!^$" };

ErrorCode process(std::string input, double* out) {
    input.erase(std::remove(begin(input), end(input), ' '), end(input));
    char operation = findCommand(input, allowedChars);
    
    if (validateCharacters(input)) {
        return ErrorCode::BadCharacter;
    }
    if (!validateFormat(input)) {
        return ErrorCode::BadFormat;
    }

    if ((!isInteger(lhs) || !isInteger(rhs)) && operator == '%'){
                return ErrorCode::ModuleOfNonIntegerValue;
    }

    if (rhs == 0 && operation == '/') {
                return ErrorCode::DivideBy0;
    }    

        
    
    std::string::size_type sz;
    double lhs = parseLhs(input, sz);
    double rhs = parseRhs(input, sz, symbol);

    
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

bool isInteger (double num) {
    return std::floor(num) == num;
}