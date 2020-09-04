#include <iostream>
#include <string>

#include "advancedCalculator.hpp"

int main() {
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        double result{};

        process(input, &result);

        std::cout << result << '\n';
    }

    return 0;
}
