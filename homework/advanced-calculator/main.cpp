#include <iostream>

#include "advancedCalculator.hpp"

int main() {
    std::string input{"-123.4 $ -1"};
    double res{0};
    std::cout << process(input, &res) << "\n";
    std::cout << std::fixed << res << "\n";

    return 0;
}
