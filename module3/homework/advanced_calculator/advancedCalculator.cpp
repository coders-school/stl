#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <regex>

// Lambdas
auto factorial = [](double a, double b)     { return a <= 1 ? 1 : a * std::tgamma(a); };
auto power = [](double a, double b)         { return std::pow(a, b); };
auto root = [](double a, double b)          { return std::pow(a, 1 / b); };

const std::map<std::string, std::function<double(double, double)>> operations{
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
    int res = n / 1;
    if(n <= 0 || n >= 0 && res * 1 == n){
        return true;
    }
    else{
        return false;
    }
}

std::vector<std::string> checkRegex(std::string input){
    const std::regex expRegex("(([-]?\\d+\\.?\\d*)([-+*\\/^$%])([-]?\\d+\\.?\\d*)?)$");
    const std::regex facRegex("([-]?\\d+\\.?\\d*)([!])?");
    std::smatch regexMatch;
    std::vector<std::string> result;

    if (std::regex_match(input, regexMatch, expRegex)) {
        result.push_back(regexMatch[2]);
        result.push_back(regexMatch[3]);
        result.push_back(regexMatch[4]);
    } else if (std::regex_match(input, regexMatch, facRegex)) {
        result.push_back(regexMatch[1]);
        result.push_back(regexMatch[2]);
    }

    return result;
}

bool badCharacter(std::string input){
    std::vector<char> operationCharacters {'+', '-', '*', '/', '^', '$', '!', '%', '.'};

    return std::any_of(input.begin(),input.end(), [&operationCharacters](char ch){
        return std::isalpha(ch) || std::ispunct(ch) && std::find(
                operationCharacters.begin(), operationCharacters.end(), ch) == operationCharacters.end();
    });
}

bool divideByZero(double secondNumber, std::string operationType){
    return operationType == "/" && secondNumber == 0;
}

bool sqrtOfNegativeNumber(double firstNumber, std::string operationType) {
    return operationType == "$" && firstNumber < 0;
}

bool moduleOfNonIntegerValue(double firstNumber, double secondNumber, std::string operationType) {
    return operationType == "%" && (!isInt(firstNumber) || !isInt(secondNumber));
}

bool badFormat(std::vector<std::string> matchResult){
    if(matchResult.size() == 0){
        return true;
    }
    return false;
}

ErrorCode process(std::string input, double* out){
    removeSpaces(input);

    if(badCharacter(input)) {
        std::cout << "bad character" << " ";
        return ErrorCode::BadCharacter;
    }

    std::vector<std::string> matchResult = checkRegex(input);

    if(badFormat(matchResult)) {
        std::cout << "bad format" << " ";
        return ErrorCode::BadFormat;
    }

    double firstNumber(std::stod(matchResult[0]));
    double secondNumber = 0;
    std::string operationType = matchResult[1];

    if(matchResult.size() > 2) {
        secondNumber = std::stod(matchResult[2]);

        if (divideByZero(secondNumber, operationType)) {
            std::cout << "divide by 0" << " ";
            return ErrorCode::DivideBy0;
        }

        if (sqrtOfNegativeNumber(firstNumber, operationType)) {
            std::cout << "sqrt of negative number" << " ";
            return ErrorCode::SqrtOfNegativeNumber;
        }

        if (moduleOfNonIntegerValue(firstNumber, secondNumber, operationType)) {
            std::cout << "module of non integer number" << " ";
            return ErrorCode::ModuleOfNonIntegerValue;
        }
    }

    *out = operations.at(operationType)(firstNumber, secondNumber);
    return ErrorCode::OK;
}
