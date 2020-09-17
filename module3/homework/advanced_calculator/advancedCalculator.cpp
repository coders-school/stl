#include "advancedCalculator.hpp"

#include <algorithm>
#include <iostream>
#include <regex>

std::string eraseSpaces(std::string input)
{
    input.erase(std::remove_if(input.begin(),
                               input.end(),
                               [](unsigned char x) { return std::isspace(x); }),
                input.end());

    return input;
}

ErrorCode allowedCharacters(std::string input)
{
    const std::string ALLOWEDCHARACTERS = "+*/-%!^$1234567890.";

    auto foundBadCharacter = input.find_first_not_of(ALLOWEDCHARACTERS);
    if (foundBadCharacter != std::string::npos) {
        return ErrorCode::BadCharacter;
    }

    return ErrorCode::OK;
}

ErrorCode allowedFormat(std::string input)
{
    std::regex patternUnary("((-?[0-9]+)|(-?[0-9]+[/.][0-9]+))(!)");
    std::regex patternBinary("((-?[0-9]+)|(-?[0-9]+[/.][0-9]+))([/+-/*///^%!/$])((-?[0-9]+)|(-?[0-9]+[/.][0-9]+))");

    std::smatch singleMatch;

    if (!std::regex_match(input, singleMatch, patternUnary) && !std::regex_match(input, singleMatch, patternBinary)) {
        return ErrorCode::BadFormat;
    }
    return ErrorCode::OK;
}

std::vector<std::string> unpackExpression(std::string input)
{
    std::regex patternUnary("((-?[0-9]+)|(-?[0-9]+[/.][0-9]+))(!)");
    std::regex patternBinary("((-?[0-9]+)|(-?[0-9]+[/.][0-9]+))([/+-/*///^%!/$])((-?[0-9]+)|(-?[0-9]+[/.][0-9]+))");

    std::smatch singleMatch;

    std::string firstNumber{};
    std::string secondNumber{};
    std::string action{};

    
    if (std::regex_match(input, singleMatch, patternUnary)) {
        firstNumber = singleMatch[1];
        action = singleMatch[4];
        secondNumber = "Unary expression";
    } 
    
    if(std::regex_match(input, singleMatch, patternBinary)) {
        firstNumber = singleMatch[1];
        action = singleMatch[4];
        secondNumber = singleMatch[5];
    }

    return {{firstNumber},{action},{secondNumber}};
}

ErrorCode process(std::string input, double* out)
{
    return ErrorCode::OK;
}

using specMap = std::map<char, std::function<void()>>;
specMap actionsHolder;
