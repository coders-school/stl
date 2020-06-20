#include "ispalindrome.hpp"

#include <algorithm>

bool is_palindrome(std::string text) {
    text.erase(std::remove_if(text.begin(), text.end(),
                              [](char rune) { return !isalpha(rune); }),
               text.end());

    std::transform(text.begin(), text.end(), text.begin(), tolower);
    return std::equal(text.cbegin(), text.cbegin() + text.size() / 2, text.crbegin());
}
