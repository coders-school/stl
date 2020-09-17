#include "advancedCalculator.hpp"

#include <iostream>
#include <string>
#include <vector>

int main(){

    std::string input {"-50.7!"};
    std::vector<std::string> allActions{};

    allActions = unpackExpression(input);

    
    for(auto action : allActions) {
        std::cout << action << "\n";
    }
    

return 0;
}
