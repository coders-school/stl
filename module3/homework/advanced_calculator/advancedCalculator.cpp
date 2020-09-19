#include "advancedCalculator.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <map>
#include <regex>

const std::map<std::string, std::function<double(double, double)>> commands{
    {"+", std::plus<double>()},
    {"-", std::minus<double>()},
    {"*", std::multiplies<double>()},
    {"/", std::divides<double>()},
    {"%", std::modulus<int>()},
    {"^", [](double base, double Pow) { return std::pow(base, Pow); }},
    {"$", [](double base, double Pow) { return std::pow(base, 1.0 / Pow); }}};

bool isBadCharacter(std::string in) {
    constexpr int numberOfCommands = 10;
    constexpr std::array<char, numberOfCommands> calculatorCommands{
        '+', '-', '*', '/', '%', '!', '^', '$', '.', ','};
    return std::any_of(in.begin(), in.end(),
                       [calculatorCommands](char c) {
                           return (std::ispunct(c) &&
                                   (std::find(calculatorCommands.begin(),
                                              calculatorCommands.end(), c) == calculatorCommands.end())) ||
                                  std::isalpha(c);
                       });
}

ErrorCode process(std::string input, double* out) {
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (std::find(input.begin(), input.end(), ',') != input.end()) {
        return ErrorCode::BadFormat;
    }

    std::regex commandPattern(R"(([-]?\d+\.\d+|[-]?\d+)\s?([+*/\-%^$])\s?([-]?\d+\.\d+|[-]?\d+))");
    std::regex factorialPattern(R"(([-]?\d+\.\d+|[-]?\d+)\s?(\!))");
    std::smatch correctInput;

    if (std::regex_search(input, correctInput, commandPattern)) {
        if (correctInput[0] != input) {
            return ErrorCode::BadFormat;
        }
        double firstValue = std::stod(correctInput[1]);
        double secondValue = std::stod(correctInput[3]);
        std::string command = correctInput[2];

        if(command == "/" && secondValue == 0){
            return ErrorCode::DivideBy0;
        } else if(command == "$" && (secondValue < 0)){
            return ErrorCode::SqrtOfNegativeNumber;
        } else if(command == "%" && (!std::isdigit(firstValue) || !std::isdigit(secondValue))){
            return ErrorCode::ModuleOfNonIntegerValue;
        }   
            *out = commands.at(command)(firstValue, secondValue);
            return ErrorCode::OK;
    } else if (std::regex_search(input, correctInput, factorialPattern)){
        if(correctInput[0] != input){
            return ErrorCode::BadFormat;
        }

        double result = std::stod(correctInput[1]);
        *out = calculateFactorial(result);
        return ErrorCode::OK
    }
    return ErrorCode::BadFormat; 
}
