#include <iostream>
#include "advancedCalculator.hpp"

void printWelcomeInformation() {
    std::cout << "****** Calcaulator ******" << '\n';
    std::cout << "Type expression or help for more information" << '\n';
}

void printHelp() {
    std::cout << "Here should be help\n";
}

int main() {
    printWelcomeInformation();
    std::string inputData;

    while (std::getline(std::cin, inputData)) {
        if (inputData == "help") {
            printHelp();
        } else if (inputData == "quit") {
            break;
        } else {
            compute(inputData);
        }
    }
    return 0;
}