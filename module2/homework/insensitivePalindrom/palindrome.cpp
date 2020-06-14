#include "palindrome.hpp"

#include <algorithm>

bool not_alpha(char ch) {
    return !isalpha(ch);
}

bool is_palindrome(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(), [](auto ch) { return tolower(ch); });
    word.erase(std::remove_if(word.begin(), word.end(), not_alpha), word.end());
    return std::equal(word.begin(), std::next(word.begin(), word.size() / 2), word.rbegin());
}