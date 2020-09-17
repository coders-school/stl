#include "advancedCalculator.hpp"

#include <iostream>

int main()
{
    std::string line;
    double result = 0.0;

    std::cout << "Advanced Calculator." << std::endl;

    while (1) {
        std::cout << "Enter expression to calculate (or q to exit): ";
        std::getline(std::cin, line);
        if (line == "q") {
            return 0;
        }
        if (ErrorCode code = process(line, &result); code == ErrorCode::OK) {
            std::cout << "Result: " << result << std::endl;
        } else {
            std::cout << "Error: " << static_cast<int>(code) << std::endl;
        }
    }

    return 0;   
}