#include "advancedCalculator.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "operacja: ";
    std::string task;
    std::getline(std::cin, task);
    double result;
    process(task, &result);
    std::cout << result << '\n';
    return 0;
}