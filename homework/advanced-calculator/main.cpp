#include <iostream>
#include "advancedCalculator.hpp"

int main() {
    double output = 0;
    double* out = &output;
    std::cout << output << '\n';
    double firstNumber = 5;
    double secondNumber = 5;
    calculator_functions['+'](firstNumber, secondNumber, out);
    std::cout << output << '\n';
    calculator_functions['-'](firstNumber, secondNumber, out);
    std::cout << output << '\n';
    calculator_functions['*'](firstNumber, secondNumber, out);
    std::cout << output << '\n';
    calculator_functions['/'](firstNumber, secondNumber, out);
    std::cout << output << '\n';
    calculator_functions['%'](firstNumber, secondNumber, out);
    std::cout << output << '\n';
    calculator_functions['!'](firstNumber, secondNumber, out);
    std::cout << output << '\n';
    calculator_functions['^'](firstNumber, secondNumber, out);
    std::cout << output << '\n';
    calculator_functions['$'](firstNumber, secondNumber, out);
    std::cout << output << '\n';

    return 0;
}