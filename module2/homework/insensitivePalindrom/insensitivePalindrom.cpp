#include "insensitivePalindrom.hpp"

bool is_palindrome(std::string word) {
    word.erase(std::remove_if(word.begin(),
                              word.end(),
                              [](char character) { return !std::isalpha(character); }),
               word.end());

    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    return (std::equal(word.begin(), word.begin() + word.size() / 2, word.rbegin()));
}
