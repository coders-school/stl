#include "advancedCalculator.hpp"
#include <iostream>
#include <algorithm>


int main () {
    double result = 0;

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        process(input, &result);
        std::cout << result << '\n';
    }

    return 0;
}