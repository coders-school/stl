#include "advancedCalculator.hpp"
#include <iostream>

int main() {
    std::string test_1 = "-3,8";
    std::cout << std::boolalpha << isBadNumber(test_1) << '\n';
    std::string test_2 = "-3 + --1,5";
    Data data;
    std::cout << std::boolalpha << isBadFormat(test_2, data) << '\n';
    std::cout << std::boolalpha << isGoodCharacter('#') << '\n';
    return 0;
}