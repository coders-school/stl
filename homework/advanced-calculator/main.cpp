#include <iostream>
#include "advancedCalculator.hpp"

int main() {
    while (true) {
        std::string input;
        std::cin >> input;

        double output;
        process(input, &output);
        std::cout << "result: " << output << "\n";               
    } 
    return 0;
}
