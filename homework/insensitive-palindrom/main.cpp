#include <iostream>
#include "palindrome.hpp"

int main() {
    std::cout << "Enter word to check: ";
    std::string word = "abbba";
    // std::cin >> word;
    std::cout << "Is palindrome?\n" << std::boolalpha << is_palindrome(word) << '\n';
}
