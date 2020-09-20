#include "advancedCalculator.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>

const std::map<char, std::function<double(double, double)>> operations {
    {'+', std::plus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    {'-', std::minus<double>()},
    {'%', std::modulus<int>()},
    {'!', [](double firstNum, double secNum) { return firstNum <= 0 ? 1.0 : std::tgamma(firstNum + 1.0 + secNum - secNum); }},
    {'^', [](auto firstNum, auto secNum) { return std::pow(firstNum, secNum); }},
    {'$', [](auto firstNum, auto secNum) { return pow(firstNum, 1.0 / secNum); }}
};

void removeSpace(std::string & input) {
    input.erase(std::remove_if(input.begin(), input.end(), [](auto el) { return std::isspace(el); }), input.end());
}

void startCalculate() {
    printWelcomeScreen();
    mainLoop();
    printGoodByeScreen();
}

void printWelcomeScreen() {
    std::cout << "Welcome in calculator for professionals. \n";
}

void makeAction(Action choice) {
    switch (choice) {
        case Action::Calculate: {
            std::string input;
            removeSpace(input);
            double output;
            std::getline(std::cin, input);
            process(input, & output);
            std::cout << "Result \n" << output;
            break;
        }
        case Action::Help: {
            printHelp();
            break;
        }
        case Action::Exit: {
            break;
        }
        default:
            std::cout << "I can't do this. \n";  
    }
}

void mainLoop() {
    while (true) {
        std::cout << "Choose what you want to do: \n"
                  << "1 - calculate \n 2 - help \n 3 - end \n";
        int pickAction;
        std::cin >> pickAction;
        makeAction(static_cast<Action>(pickAction));
        if (static_cast<Action>(pickAction) == Action::Exit) {
            break;
        }
    }
}

void printHelp() {
    std::cout << "You can use operations: \n"
              << "Add [+] \n"
              << "Multiply [*] \n"
              << "Divide [/] \n"
              << "Substract [-] \n"
              << "Modulo [%] \n"
              << "Factorial [!] \n"
              << "Power [^] \n"
              << "Root [$] \n ";
}

void printGoodByeScreen() {
    std::cout << "Thank you for using our services. \n";
}

bool isComma(const char input) {
    return input == '.' || ',';
}

bool isBadCharacter(std::string input) {
    return (std::any_of(input.cbegin(), input.cend(), [](auto el) { 
        return !(std::isdigit(el) || isComma(el) || operations.find(el) != operations.cend()); }));
}

bool isBadFormat(std::string input) {
    return false;
}

bool isDivideBy0(std::string input) {
    return false;
}

bool isSqrtOfNegativeNumber(std::string input) {
    return false;
}

bool isModuleOfNonIntegerValue(std::string input) {
    return false;
}

ErrorCode process(std::string input, double* out) {
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }

    return ErrorCode::OK;
}
