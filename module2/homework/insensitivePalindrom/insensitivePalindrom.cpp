#include "insensitivePalindrom.hpp"

#include <algorithm>
bool is_palindrome(std::string text) {
    auto removeSpecialChars = [](char& c) {
        c = std::tolower(c);
        return !std::isalpha(c);
    };

    auto pos = std::remove_if(text.begin(), text.end(), removeSpecialChars);
    text.erase(pos, text.end());

    return (std::equal(text.begin(), text.begin() + text.size() / 2, text.rbegin()));
}
