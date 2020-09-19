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
    std::regex patternUnary("(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))(!)");
    std::regex patternBinary("(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))([-/+/*///^%!/$])(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))");

    std::smatch singleMatch;

    if (!std::regex_match(input, singleMatch, patternUnary) && !std::regex_match(input, singleMatch, patternBinary)) {
        return ErrorCode::BadFormat;
    }
    return ErrorCode::OK;
}

std::vector<std::string> unpackExpression(std::string input)
{
    std::regex patternUnary("(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))(!)");
    std::regex patternBinary("(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))([-/+/*///^%!/$])(([-]?[0-9]+)|([-]?[0-9]+[/.][0-9]+))");

    std::smatch singleMatch;

    std::string firstNumber{};
    std::string action{};
    std::string secondNumber{};

    
    if (std::regex_match(input, singleMatch, patternUnary)) {
        firstNumber = singleMatch[1];
        action = singleMatch[4];
        secondNumber = "Unary expression";
    } 
    
    if(std::regex_match(input, singleMatch, patternBinary)) {
        for(auto match : singleMatch) {
            std::cout << match << "\n";
        }
        firstNumber = singleMatch[1];
        action = singleMatch[4];
        secondNumber = singleMatch[5];
    }

    return {{firstNumber},{action},{secondNumber}};
}

ErrorCode prohibitedOperations(std::vector<std::string> unpackedElements) {

    double firstNumber = std::stod(unpackedElements[0]);
    std::string action = unpackedElements[1];
    double secondNumber = std::stod(unpackedElements[2]);

    if((action == "/") && (!secondNumber)){
        return ErrorCode::DivideBy0;
    }

    if((action == "%") && (!std::isdigit(secondNumber))){
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    if((action == "$") && (firstNumber < 0)){
        return ErrorCode::SqrtOfNagativeNumber;
    }
    

    return ErrorCode::OK;

}

ErrorCode process(std::string input, double* out)
{
    ErrorCode errorCode {ErrorCode::OK};
    std::vector<std::string> unpackedElements{}; 

    input = eraseSpaces(input);
    errorCode = allowedCharacters(input);
    errorCode = allowedFormat(input);
    unpackedElements = unpackExpression(input);

    errorCode = prohibitedOperations(unpackedElements);


    return errorCode;
}

using specMap = std::map<char, std::function<void()>>;
specMap actionsHolder;
