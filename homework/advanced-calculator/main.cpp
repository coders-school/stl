#include <iostream>
#include <string>
#include "advancedCalculator.hpp"

int main() {
    std::cout << "zrn: ";
    double a;
    std::string str;
    std::getline(std::cin, str);
    process(str, &a);
    std::cout << "result " << a << '\n';
    return 0;
}