#include "advancedCalculator.hpp"

int main()
{
    
    double result = 0;
    std::string input = " ";

    std::cout <<"Calculator\n";
    while (input != "quit") 
    {
        getline(std::cin, input);
        process(input, &result);
        std::cout <<result<<"\n";
    }
    
    

}
