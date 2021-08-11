#include "palindrome.hpp"
#include <algorithm>
#include <cctype>

bool is_palindrome (std::string str) {
    auto it = std::remove_if (str.begin(), str.end(), [](char letter){return !isalpha (letter);});
    str.erase(it, str.end());
    std::transform (str.begin(), str.end(), str.begin(), [](char letter){return std::toupper(letter);});

    return std::equal(str.begin(), str.begin() + str.size()/2, str.rbegin());
}