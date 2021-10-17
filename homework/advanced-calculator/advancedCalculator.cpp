#include "advancedCalculator.hpp"
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
// #include <string>

ErrorCode process(std::string input, double* out) {

    size_t position;
    double firstNumber = std::stod(input, &position);
    input.erase(0, position);
    // std::cout << "after first " << input << '\n';

    // std::erase_if(input, std::isspace);

    std::erase(input, ' ');
    // std::cout << input << "after erase \n";
    // input.erase()
    char operation = input[0];  // wczesniej 1
    input.erase(0, 1); // wczensiej 0, 2
    double secondNumber = 1.0; 
    if (operation != '!') {
        secondNumber = std::stod(input);
    }

    // std::cout << firstNumber << '_' << operation << '_' << secondNumber << '\n';
    // std::function<int(int, int)> factorial = [&factorial](int a, int b) -> int {return a < 2 ? 1 : (a * factorial(a - 1, a));};
    std::function<double(double, double)> factorial = [&factorial](double a, double b) -> double {return a < 2 ? 1 : (a * factorial(a - 1, a));};

    // std::cout << "uuuuu \n\n   : " << factorial(2, 3) << "\n----\n";

    // std::map<char, std::function<double(double, double)>> operations {
    std::map<char, std::function<double(double, double)>> operations {
        {'+', [](double a, double b){return a + b;}},
        {'-', [](double a, double b){return a - b;}},
        {'*', [](double a, double b){return a * b;}},
        {'/', [](double a, double b){return a / b;}},
        {'%', [](int a, int b){return a % b;}},
        {'^', [](double a, double b){return std::pow(a, b);}},
        {'$', [](double a, double b){return std::pow(a, 1/b);}},
        {'!', factorial}

    };

    *out = operations[operation](firstNumber, secondNumber);

    return ErrorCode::OK;
}