#include <iostream>

#include "insensitivePalindrom.hpp"

int main() {
    std::string wordsToCheckIfPalindrome = "No lemon, no melon";

    if (is_palindrome(wordsToCheckIfPalindrome)) {
        std::cout << "It is palindrome\n";
    } else {
        std::cout << "It is not palindrome\n";
    }
    return 0;
}