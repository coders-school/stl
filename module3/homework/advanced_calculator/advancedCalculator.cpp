#include "advancedCalculator.hpp"
#include <iostream>

void startCalculate() {
    printWelcomeScreen();
    calculate();
    printGoodByeScreen();
}

void printWelcomeScreen() {
    std::cout << "Welcome in calculator for professionals. \n";
}

void calculate() {

}

void printGoodByeScreen() {
    std::cout << "Thank you for using our application. \n";
}

ErrorCode process(std::string input, double* out) {
    return ErrorCode::OK;
}
