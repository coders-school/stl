#include "isPalindrome.hpp"

#include <algorithm>
#include <cctype>

bool is_palindrome(std::string test) {
    auto letterIterator = std::remove_if(test.begin(), test.end(), [](unsigned char c) {
        if (isupper) {
            std::tolower(c);
        }
        return !std::isalpha(c);
    });
    auto terminator = test.begin() + (letterIterator - test.begin()) / 2;
    return std::equal(test.begin(), terminator, letterIterator - 1);
    // return std::equal()
}