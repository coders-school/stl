#include "advancedCalculator.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>

ErrorCode process(std::string input, double* out)
{
    return ErrorCode::OK;
}

bool quitRequested(std::string line)
{
    std::transform(begin(line), end(line), begin(line), tolower);

    return line == "quit";
}

void printInstructions()
{
    std::cout << "-----Simple calculator-----\n"
              << "type 'quit' or enter a calculation to be performed\n";
}