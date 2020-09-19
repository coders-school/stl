#include "advancedCalculator.hpp"

#include <iostream>
#include <string>
#include <vector>

int main()
{
    ErrorCode ec{};
    double result{};
    std::string input;
    std::cin >> input;

    while (input != "exit") {
        process(input, &result);
        if ((int)ec == 0) {
            std::cout << result << "\n";
        }
        else {
            std::cout << "Bad input!\n";
        }
        std::cin >> input;
    }

    return 0;
}
