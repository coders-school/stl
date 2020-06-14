#include "palindrome.hpp"

#include <algorithm>

bool is_palindrome(std::string str) {
    str.erase(std::remove_if(str.begin(), str.end(),
                             [](char element) { return !std::isalpha(element); }),
              str.end());
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return (std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin()));
}
