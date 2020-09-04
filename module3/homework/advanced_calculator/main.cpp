#include "advancedCalculator.hpp"

void printInfo() {
    std::cout << "\nCalculator Functions:\n"
              << "Add \"+\" \n"
              << "Substract \"-\"\n"
              << "Multiply \"*\"\n"
              << "Divide \"/\"\n"
              << "Modulo \"%\"\n"
              << "Power \"^\"\n"
              << "Root \"$\"\n"
              << "Factorial \"!\"\n"
              << "Examples:\n"
              << "[1] 2.54 + -3.12\n"
              << "[2] 7!\n\n";
}

int main() {
    std::cout << "#######################"
              << "      Advanced Calculator      "
              << "#######################\n"
              << "Type \"q\" to quit or type \"info\" to get informations about calculator options.\n\n";

    std::string inputData;

    while (true) {
        getline(std::cin, inputData);

        if (inputData == "q") {
            break;
        }

        if (inputData == "info") {
            printInfo();
        } else {
            calculate(inputData);
        }
    }

    return 0;
}