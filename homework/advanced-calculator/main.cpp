#include "advancedCalculator.hpp"
#include <iostream>
#include <string>

int main() {
    double result;
    std::string expression;
    while(true) {
        std::cout << "Expression: ";
        std::getline(std::cin, expression);
        if(expression == "exit") {
            break;
        }
        if(process(expression, &result) != ErrorCode::OK) {
            continue;
        }
        std::cout << "Result: " << result << '\n';
    }
    return 0;
}