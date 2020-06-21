#include "checkPalindrome.hpp"

#include <algorithm>
#include <iostream>
#include <string>

bool is_palindrome(std::string str) {
    str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char x) {
                  return !std::isalpha(x) || std::isspace(x);
              }),
              str.end());

    std::transform(str.begin(), str.end(), str.begin(), [](auto x) {
        return std::tolower(x);
    });

    return std::equal(str.cbegin(), str.cbegin() + str.size() / 2, str.crbegin());
}
