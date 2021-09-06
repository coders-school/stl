#include "advancedCalculator.hpp"
#include <algorithm>
#include <iostream>
#include <regex>

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

    if(validateInput(input)){
        int offset = 0;
        double lhs = parseLHS(input);
        char operation = parseOperator(input, offset);
        double rhs = parseRHS(input, offset);
        std::cout<<lhs;
        std::cout<<operation;
        std::cout<<rhs<<'\n';

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
    
    } else {
        *out = 0.0;
        if (hasBadCharacters(input)) {
            return ErrorCode::BadCharacter;
        }

        return ErrorCode::BadFormat;
    }
        
}

bool hasBadCharacters(const std::string& input){
    const std::vector<char> acceptedCharacters{'+', '-', '*', '/', '%', '!', '^', '$', '.', ',',
                                               '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '};
    return std::any_of(input.begin(),
                       input.end(),
                       [&acceptedCharacters](const char& character) {
                           return std::find(acceptedCharacters.begin(),
                                            acceptedCharacters.end(),
                                            character) == acceptedCharacters.end();
                       });
}

bool isInteger (const double& num) {
    return std::floor(num) == num;
}


bool isFactorial(const std::string& input){
    std::regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?\\!$");
    return std::regex_match (input,regexp);
}

bool hasDoubleMinus(const std::string& input){
    std::regex regexp(".*\\-{2}.*");
    return std::regex_match (input,regexp);
}

bool validateInput(const std::string& input){
    std::regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?[\\%\\$\\^\\+\\-\\*\\/](-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    return (std::regex_match (input,regexp) || isFactorial(input));
}

double parseLHS(const std::string& input){
    std::regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?");
    std::smatch m;
    std::regex_search(input, m, regexp);
    if(m[0].length()!=0){
        return std::stod(m[0]);
    }
    return 0.0;
}

char parseOperator(const std::string& input, int& offset){
    std::regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?[\\%\\$\\^\\+\\-\\*\\/\\!]");
    std::smatch m;
    std::regex_search(input, m, regexp);
    if(m[0].length()!=0){
        std::string lhs = m[0];
        offset = lhs.length();
        return lhs.back();
    }
    return 0.0;
}

double parseRHS(const std::string& input, const int& offset){
    if(isFactorial(input)){
        return 0.0;
    }
    return std::stod(input.substr(offset));
}