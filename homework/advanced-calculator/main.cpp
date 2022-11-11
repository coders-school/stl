#include "advancedCalculator.hpp"
#include <iostream>

int main()
{
    std::string input;
    double result;
    for(;;)
    {
        std::cout << "Give data to calculate (format: number operator number): " << std::endl;
        std::cin >> input;
        auto error = process(input, &result);
        if(error == ErrorCode::OK)
        {
            std::cout << "Result " << result<< std::endl;
            break;
        }
        else
        {
            std::cout << "Error: " << error <<std::endl;
        }
    }
    return 0;
}