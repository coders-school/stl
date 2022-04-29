#include <iostream>
#include "advancedCalculator.hpp"

int main() {
    std::string task;
    std::cout << "\"Advanced\" calculator:\n";
    std::getline(std::cin, task);
    double output;
    process(task, &output);
    std::cout << "= " << output << '\n';
    return 0;
}