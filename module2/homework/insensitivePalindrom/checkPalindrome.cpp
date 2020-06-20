#include "checkPalindrome.hpp"
#include <string>
#include <algorithm>
#include <iostream>

bool is_palindrome(std::string str)
{
    str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char x) {
                  return !std::isalpha(x) || std::isspace(x);
              }),
              str.end());

    std::transform(str.begin(), str.end(), str.begin(), [](auto x) {
        return std::tolower(x);
    });

    bool palindrome = std::equal(str.begin(), str.end(), str.rbegin());
    return palindrome;
}
