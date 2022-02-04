#include <iostream>   //REMOVE

#include "advancedCalculator.hpp"

int main()
{
    std::string user_input;
    printInstructions();
    while (std::getline(std::cin, user_input) && !quitRequested(user_input)) {
        double result {};
        auto returned_state = process(user_input, &result);
        printResult(returned_state, result);
        printInstructions();
    }
    std::cout << "!!!!!! Thank you for trying out my calculator !!!!!!!!"
              << std::endl;

    return 0;
}
