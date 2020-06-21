#include "palindrome.hpp"

bool is_palindrome(std::string text) {
    text.erase(std::remove_if(text.begin(), text.end(), [](char letter) { return !isalpha(letter); }), text.end());
    std::transform(text.begin(), text.end(), text.begin(), tolower);
    return std::equal(text.cbegin(), text.cbegin() + text.size() / 2, text.crbegin());
}
