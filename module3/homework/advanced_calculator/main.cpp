#include "advancedCalculator.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

int main() {
    std::string input;
    std::string dash(80, '-');

    while (true) {
        std::cout << "Enter your equation: (q to exit) \n";
        std::getline(std::cin, input);
       
        if (input == "q") {
            break;
        }

        double result = 0;
        auto ec = process(input, &result);
        if (ec != ErrorCode::OK) {
            std::cout << errorOutput.find(ec)->second << "\n";            
        } else {
            std::cout << "\nResult: " << result << '\n'
                      << dash << '\n'
                      << '\n';
        }

        input.clear();
    }

    return 0;
}
