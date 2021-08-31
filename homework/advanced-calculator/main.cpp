#include "advancedCalculator.hpp"
#include <iostream>
#include <algorithm>


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

    double result = 0;

    std::string test = "225 $3";
    // std::string test2 = "2 + 2";
    // std::string test3 = "123 \\ 123";

    // std::cout << '\n';
    // std::cout << std::boolalpha << validateCharacters(test);
    // std::cout << std::boolalpha << validateCharacters(test2);
    // std::cout << std::boolalpha << validateCharacters(test3);

    std::cout << process(test, &result);
}