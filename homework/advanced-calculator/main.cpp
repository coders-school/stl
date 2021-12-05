
#include <iostream>
#include <string>
#include "advancedCalculator.hpp"
int main()
{
    double output;
    std::string input;
    std::getline(std::cin, input);

    auto error = process(input, &output);

    
}