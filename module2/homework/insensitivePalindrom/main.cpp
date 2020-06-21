#include <iostream>

#include "insensitivePalindrome.hpp"

int main() {
    std::string wordsToCheckIfPalindrome = "Eva, can I see bees in a cave?";
    if (is_palindrome(wordsToCheckIfPalindrome)) {
        std::cout << "It's palindrome\n";
    } else {
        std::cout << "It's not palindrome\n";
    }
    return 0;
}
