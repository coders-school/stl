#include <iostream>
#include "advancedCalculator.hpp"
int main() {
    auto out = Calculator::calculate('+', 10, 2);
    std::cout << "out: " << out << "\n";
}