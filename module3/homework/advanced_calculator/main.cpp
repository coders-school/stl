#include <iostream>
#include "advancedCalculator.hpp"
#include "exercise4.cpp"
int main() {
    double out1{};
    process("5+ 11", &out1);
    process("11,3 + 12.4", &out1);
    auto out = Calculator::calculate('+', 10, 2);
    std::cout << "out: " << out << "\n";
}