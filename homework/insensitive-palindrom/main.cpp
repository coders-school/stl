#include <iostream>
#include "palindrome.hpp"

int main() {
    std::string string =
        "Red rum, sir, is murder";
    std::cout << "String: " << string << '\n';
    std::cout << "Is the string palindrome? " << std::boolalpha << is_palindrome(string) << '\n';
}
