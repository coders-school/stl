#include <functional>
#include <iostream>
#include <map>
#include <string>
#include "advancedCalculator.hpp"

int main() {
    std::string userInput;
    double out{0};
    while (true) {
        std::getline(std::cin, userInput);

        if (userInput == "Quit") {
            break;
        }

        process(userInput, &out);
        out = 0;
    }
    return 0;
}