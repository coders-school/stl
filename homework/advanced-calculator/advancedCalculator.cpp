#include "advancedCalculator.hpp"
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
// #include <string>

bool isValidOperation(char c) {
    return c == '+' ||  c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '$' || c == '!';
}

ErrorCode process(std::string input, double* out) {

    if (std::any_of(input.begin(), input.end(), [](auto c){return !(isdigit(c) || isValidOperation(c) || isspace(c)|| c == '.');}) ) {
        return ErrorCode::BadCharacter;
    }

    bool badFormat = false;

    auto isOperationButNotMinus = [](auto c){ return isValidOperation(c) && c != '-';};
    auto operationCounter = std::count_if(input.begin(), input.end(), isOperationButNotMinus);

    if (isOperationButNotMinus(*input.begin())          // has operation sign at the beginning
        || operationCounter > 2
        ||  ) {

    }

    // if (isValidOperation(*input.begin()) && *input.begin() != '-' ) {
    if (isValidOperation(*input.begin()) && *input.begin() != '-' ) {

    }


    for (auto it = input.begin(); it != input.end(); it++) {
        
    }

    size_t position;
    double firstNumber = std::stod(input, &position);
    input.erase(0, position);
    // std::cout << "after first " << input << '\n';

    std::erase_if(input, isspace);

    // std::erase(input, ' ');
    // std::cout << input << "after erase \n";
    char operation = input[0];  // wczesniej 1
    input.erase(0, 1); // wczensiej 0, 2
    double secondNumber = 1.0; 
    if (operation != '!') {
        secondNumber = std::stod(input);
    }

    // std::cout << firstNumber << '_' << operation << '_' << secondNumber << '\n';

    std::map<char, std::function<double(double, double)>> operations {
        {'+', [](double a, double b){return a + b;}},
        {'-', [](double a, double b){return a - b;}},
        {'*', [](double a, double b){return a * b;}},
        {'/', [](double a, double b){return a / b;}},
        {'%', [](int a, int b){return a % b;}},
        {'^', [](double a, double b){return std::pow(a, b);}},
        {'$', [](double a, double b){return std::pow(a, 1/b);}},
        {'!', [](double a, double b){return a < 0 ? -std::tgamma(-a + 1) : std::tgamma(a + 1);}}

    };

    *out = operations[operation](firstNumber, secondNumber);

    return ErrorCode::OK;
}