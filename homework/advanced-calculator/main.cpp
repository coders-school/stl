#include "advancedCalculator.hpp"
#include <iostream>

int main () {
    // std::cout << commands.find('+')->second(2,2) << '\n';
    // std::cout << commands.find('-')->second(4,2) << '\n';
    // std::cout << commands.find('*')->second(2,2) << '\n';
    // std::cout << commands.find('/')->second(2,2) << '\n';
    // std::cout << commands.find('%')->second(10,2) << '\n';
    // std::cout << commands.find('!')->second(-4,2) << '\n';
    // std::cout << commands.find('^')->second(10,2) << '\n';
    // std::cout << commands.find('$')->second(2,3) << '\n';
    // 



    std::string test = "123.5 123";
    std::string::size_type sz;
    // std::cout << std::stod(test, lhs) << '\n';
    double lhs = std::stod(test, &sz);
    double rhs = std::stod(test.substr(sz));
    std::cout << lhs << '\n';
    std::cout << rhs << '\n';
    std::cout << std::boolalpha << validateCharacters(test);
}