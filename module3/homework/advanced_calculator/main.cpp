#include <iostream>
#include <string>

#include "advancedCalculator.hpp"

int main() {
    std::string input;
    do {
        std::cout << "Enter expression to calculate (q to exit): ";
        std::getline(std::cin, input);
    } while (input != "q");
    return 0;
}
