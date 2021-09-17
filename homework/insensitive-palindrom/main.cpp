#include <iostream>
#include "palindrome.hpp"

int main() {
    std::cout << "Enter word to check: ";
    std::string word;
    std::cin >> word;

    std::cout << "Is palindrome?" << std::boolalpha << is_palindrome(word) << '\n';
}
