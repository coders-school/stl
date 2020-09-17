#include "advancedCalculator.hpp"

#include <iostream>
#include <string>
#include <vector>

int main(){

    std::string input {"-50.5*-67.9"};
    std::vector<std::string> allActions{};

    allActions = unpackExpression(input);

    std::cout << "ALL ACTIONS!\n";
    for(auto action : allActions) {
        std::cout << action << "\n";
    }
    

return 0;
}
