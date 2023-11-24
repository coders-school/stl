#include "palindrome.hpp"

#include <algorithm>
#include <iostream>
#include <string>

bool is_palindrome(std::string_view s) {
    std::string str;
    std::for_each(s.begin(), s.end(), [&str](char c) {
        if (std::isalnum(c)) {
            str += std::tolower(c);
        }
    });

    return std::equal(str.begin(), str.end(), str.rbegin(), str.rend());
}
