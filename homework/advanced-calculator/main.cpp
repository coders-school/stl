#include "advancedCalculator.hpp"
#include <iostream>

int main() {
    // breaksStringToMembers ("23+43");
    std::string s1 = "5,1!";
    Data data;
    data = parseString(s1);
    std::cout << s1 << '\n';
    return 0;
}