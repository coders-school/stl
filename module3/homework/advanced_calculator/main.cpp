#include "advancedCalculator.hpp"

#include <iostream>

int main()
{
    std::string line;
    double result;

    std::cout << "Advanced Calculator." << std::endl;

    while (1) {
        std::cout << "Enter expression to calculate (or q to exit): ";
        std::getline(std::cin, line);
        if (line == "q") {
            return 0;
        }
        process(line, &result);
        std::cout << "Result: " << result << std::endl;
    }

    return 0;   
}