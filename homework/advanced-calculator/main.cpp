#include "advancedCalculator.hpp"
#include <iostream>

int main() {
    double output = 0;
    std::string value;

    while (getline(std::cin, value)) {
        ErrorCode w = process(value, &output);
        std::cout << "ErrorCode = " << int(w) << '\n';
        std::cout << "output = " << output << '\n';
        output = 0;
        if (value == "end") {
            break;
        }
    }

    return 0;
}