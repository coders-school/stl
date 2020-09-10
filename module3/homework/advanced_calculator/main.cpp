#include <cmath>
#include <iostream>
#include <string>

#include "advancedCalculator.hpp"

int main() {
    std::string text;
    std::string dash(40, '-');
    while (true) {
        std::cout << "Enter your equation: (q to finish) \n";
        std::getline(std::cin, text);
        if (text == "q" || text == "Q") {
            break;
        }
        double result = 0;
        process(text, &result);
        std::cout << "Result: " << result << '\n';
        std::cout << dash << '\n';
    }
}
