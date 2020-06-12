#include "palindrom.hpp"

#include <algorithm>

bool is_palindrome(char* arr) {
    std::string str(arr);
    str.erase(std::remove_if(str.begin(), str.end(),
                             [](char c) { return std::isspace(c) || std::isalpha(c); }),
              str.end());
    return (std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin()));
}
