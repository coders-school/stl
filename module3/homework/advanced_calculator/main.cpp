#include "advancedCalculator.hpp"

#include <iostream>
#include <string>
#include <vector>

int main(){

    std::string input {"5.5-5.5"};
    std::vector<std::string> allActions{};

    allActions = unpackExpression(input);

    std::cout << "ALL ACTIONS!\n";
    for(auto action : allActions) {
        std::cout << action << "\n";
    }
    

return 0;
}
