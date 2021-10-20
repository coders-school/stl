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

    if (std::any_of(input.begin(), input.end(), [](auto x){return !(isdigit(x) || isValidOperation(x) || isspace(x)|| x == '.');}) ) {
        return ErrorCode::BadCharacter;
    }

    if (isValidOperation(*input.begin()) && *input.begin() != '-' ) {

    }



    size_t position;
    double firstNumber = std::stod(input, &position);
    input.erase(0, position);
    // std::cout << "after first " << input << '\n';

    std::erase_if(input, isspace);



    // for (auto it = input.begin(); it != input.end();) {
    // }


    // std::erase(input, ' ');
    // std::cout << input << "after erase \n";
    // input.erase()
    char operation = input[0];  // wczesniej 1
    input.erase(0, 1); // wczensiej 0, 2
    double secondNumber = 1.0; 
    if (operation != '!') {
        secondNumber = std::stod(input);
    }

    // std::cout << firstNumber << '_' << operation << '_' << secondNumber << '\n';

    // std::map<char, std::function<double(double, double)>> operations {
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