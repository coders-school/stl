#include <cmath>
#include <iostream>
#include <string>

#include "advancedCalculator.hpp"

int main() {
    std::string text;
    std::getline(std::cin, text);
    double result = 0;
    process(text, &result);
    std::cout << result << '\n';    
}
