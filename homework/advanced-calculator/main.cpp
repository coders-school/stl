#include "advancedCalculator.hpp"
#include <iostream>
#include <algorithm>


int main () {
    double result = 0;

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        if (input == "exit"){
            return false;
        }
        process(input, &result);
        std::cout << result << '\n';
    }

    std::cout << process("123.1 % 0", &result) << '\n';

    return 0;
}