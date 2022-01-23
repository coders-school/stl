#include "advancedCalculator.hpp"

int main()
{
    std::string input;
    double output;

    while (true)
    {
        std::getline(std::cin, input);
        process(input, &output);
    }
}
