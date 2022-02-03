#include <iostream>   //REMOVE

#include "advancedCalculator.hpp"

int main()
{
    std::string user_input;
    printInstructions();
    while (std::getline(std::cin, user_input) && !quitRequested(user_input)) {
        // REMOVE
        checkFormatErrors(user_input);
    }

    return 0;
}
