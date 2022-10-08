#include "insensitivePalindrom.hpp"

#include <algorithm>

bool is_palindrome(const std::string& word) {
    std::string wordAlphabetic;
    std::copy_if(word.cbegin(), word.cend(), std::back_inserter(wordAlphabetic), [](char c) {
        return isalpha(c);
    });
    std::transform(wordAlphabetic.begin(), wordAlphabetic.end(), wordAlphabetic.begin(), [](char c) {
        return tolower(c);
    });
    return std::equal(wordAlphabetic.cbegin(), wordAlphabetic.cend(), wordAlphabetic.crbegin());
}
