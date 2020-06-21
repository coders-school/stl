#include "insensitivePalindrome.hpp"

#include <algorithm>

bool is_palindrome(std::string words) {
    words.erase(std::remove_if(words.begin(),
                               words.end(),
                               [](char element) { return !std::isalpha(element); }),
                words.end());
    std::transform(words.begin(), words.end(), words.begin(), ::tolower);
    return (std::equal(words.begin(), words.begin() + words.size() / 2, words.rbegin()));
}
