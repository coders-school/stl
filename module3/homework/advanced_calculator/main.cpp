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

        ec = process(input, &result);
        if ((int)ec == 0) {
            std::cout << result << "\n";
        }
        if ((int)ec == 1) {
            std::cout << "Bad Format, try again!\n";
            result = 0;
        }
        if ((int)ec == 2) {
            std::cout << "Bad Character, try again!\n";
            result = 0;
        }
        if ((int)ec == 3) {
            std::cout << "Divide by 0, try again!\n";
            result = 0;
        }
        if ((int)ec == 4) {
            std::cout << "Module Of Non Integer Value, try again!\n";
            result = 0;
        }
        else if ((int)ec == 5) {
            std::cout << "Sqrt Of Negative Number, try again!\n";
            result = 0;
        }
        std::cin >> input;
    }

    return 0;
}
