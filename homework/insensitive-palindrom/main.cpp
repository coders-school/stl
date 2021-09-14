#include "palindrome.hpp"
#include <iostream>

int main() {
    std::string str = "Eva, can I see bees in a cave?";
    std::cout << std::boolalpha << is_palindrome(str) << '\n';
    return 0;
}