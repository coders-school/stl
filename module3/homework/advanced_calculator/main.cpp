#include <cmath>
#include <iostream>
#include <string>

#include "advancedCalculator.hpp"

int main() {
    std::string text;
    while (true) {
        std::getline(std::cin, text);
        double result = 0;
        process(text, &result);
        if (text == "q") {
            break;
        }
    }

    // std::cout << result << '\n';
}
