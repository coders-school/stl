#include "advancedCalculator.hpp"
#include <cmath>
#include <iostream>

void startCalculate() {
    printWelcomeScreen();
    calculate();
    printGoodByeScreen();
}

void printWelcomeScreen() {
    std::cout << "Welcome in calculator for professionals. \n";
}

void makeAction(Action choice) {
    switch (choice) {
        case Action::Calculate {
        break;
        }
        case Action::Help {
        printHelp();
        break;
        }
        case Action::Exit {
        break;
        }
    }
}

void calculate() {
    while(true) {
        std::cout << "Choose what you want to do: \n
                     "1 - calculate \n 2 - help \n 3 - end \n"
        void makeAction();
        break;
    }
}

void printHelp() {
    std::cout << "You can use operations: \n
                  Add [+] \n 
                  Multiply [*] \n 
                  Divide [/]\n
                  Substract [-] \n
                  Modulo [%] \n
                  Factorial [!]\n
                  Power [^]\n  
                  Root [$]\n"
}

void printGoodByeScreen() {
    std::cout << "Thank you for using our services. \n";
}

ErrorCode process(std::string input, double* out) {
    return ErrorCode::OK;
}

const std::map<std::string, std::function<double(double, double)>> operations{
    {"+", std::plus<double>()},
    {"*", std::multiplies<double>()},
    {"/", std::divides<double>()},
    {"-", std::minus<double>()},
    {"%", std::modulus<int>()},
    {"!", [](double firstNum, double secNum) { return firstNum <= 0 ? 1.0 : std::tgamma(firstNum + 1.0 + secNum - secNum); }},
    {"^", [](auto firstNum, auto secNum) { return std::pow(firstNum, secNum); }},
    {"$", [](auto firstNum, auto secNum) { return pow(firstNum, 1.0 / secNum); }}
};
