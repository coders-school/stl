#include "advancedCalculator.hpp"

#include <cmath>
#include <langinfo.h>

// Lambdas
auto factorial = [](double a, double b)     { return a <= 1 ? 1 : a * std::tgamma(a); };
auto power = [](double a, double b)         { return std::pow(a, b); };
auto root = [](double a, double b)          { return std::pow(a, 1 / b); };

std::map<std::string, std::function<double(double, double)>> operations{
        {"+", std::plus<double>()},
        {"-", std::minus<double>()},
        {"*", std::multiplies<double>()},
        {"/", std::divides<double>()},
        {"%", std::modulus<int>()},
        {"!", factorial},
        {"^", pow},
        {"$", root}
};

void removeSpaces(std::string& input){
    input.erase(std::remove_if(input.begin(), input.end(), [](char ch){
        return std::isspace(ch);
    }), input.end());
}

bool isInt(double n){
    int res=n/1;
    if(n<=0 || n>=0 && res*1==n)
        return true;
    else
        return false;
}

std::vector<std::string> expressionRegex(std::string input){
    std::regex expRegex("(([-]?\\d+\\.?\\d*)([-+*\\/^$%])([-]?\\d+\\.?\\d*)?)$");
    std::regex facRegex("^(\\d+\\.?\\d*)([!])?");
    std::smatch regexMatch;
    std::vector<std::string> result;

    if (std::regex_match(input, regexMatch, expRegex)) {
        std::cout << " what?! ";
        result.push_back(regexMatch[2]);
        result.push_back(regexMatch[3]);
        result.push_back(regexMatch[4]);
    } else if (std::regex_match(input, regexMatch, facRegex)) {
        std::cout << " yes ";
        result.push_back(regexMatch[2]);
        result.push_back(regexMatch[3]);
    }

    return result;
}

bool badCharacter(std::string input){
    std::vector<char> operationCharacters {'+', '-', '*', '/', '^', '$', '!', '%', '.'};

    return std::any_of(input.begin(), input.end(), [&operationCharacters](char ch){
        return std::isalpha(ch) || std::ispunct(ch) && std::find(
                operationCharacters.begin(), operationCharacters.end(), ch) == operationCharacters.end();
    });
}

bool divideByZero(std::vector<std::string> matchResult){
    double secondNumber = std::stod(matchResult[2]);
    std::string operationType = matchResult[1];

    if(operationType == "/" && secondNumber == 0)
        return true;
    return false;
}

bool sqrtOfNegativeNumber(std::vector<std::string> matchResult) {
//    double secondNumber = std::stod(matchResult[2]);
//    std::string operationType = matchResult[1];
//
//    if(operationType == "$" && secondNumber < 0)
//        return true;
    return false;
}

bool moduleOfNonIntegerValue(std::vector<std::string> matchResult) {
    double firstNumber = std::stod(matchResult[0]);
    double secondNumber = std::stod(matchResult[2]);
    std::string operationType = matchResult[1];

    if(operationType == "%" && (!isInt(firstNumber) || !isInt(secondNumber)))
        return true;
    return false;
}

ErrorCode process(std::string input, double* out){
    removeSpaces(input);
    std::vector<std::string> matchResult = expressionRegex(input);

    if(badCharacter(input)) {
        std::cout << "bad character" << " ";
        return ErrorCode::BadCharacter;
    }

    double firstNumber(std::stod(matchResult[0]));
    double secondNumber(std::stod(matchResult[2]));
    std::string operationType = matchResult[1];
    std::cout << firstNumber << operationType << secondNumber;

    if(matchResult.size() == 0) {
        std::cout << "bad format" << " ";
        return ErrorCode::BadFormat;
    }

    if(divideByZero(matchResult)){
        std::cout << "divide by 0" << " ";
        return ErrorCode::DivideBy0;
    }

    if(sqrtOfNegativeNumber(matchResult)){
        std::cout << "sqrt of negative number" << " ";
        return ErrorCode::SqrtOfNegativeNumber;
    }

    if(moduleOfNonIntegerValue(matchResult)){
        std::cout << "module of non integer number" << " ";
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    *out = operations.at(operationType)(firstNumber, secondNumber);
    return ErrorCode::OK;
}