#include "advancedCalculator.hpp"
#include <algorithm>
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
    std::cout << input << "after erase \n";
    // input.erase()
    char operation = input[0];  // wczesniej 1
    input.erase(0, 1); // wczensiej 0, 2
    double secondNumber = std::stod(input);

    std::cout << firstNumber << '_' << operation << '_' << secondNumber << '\n';
    
    std::map<char, std::function<double(double, double)>> operations {
        {'+', [](double a, double b){return a + b;}},
        {'-', [](double a, double b){return a - b;}},

    };

    *out = operations[operation](firstNumber, secondNumber);

    return ErrorCode::OK;
}