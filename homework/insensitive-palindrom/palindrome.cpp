#include "palindrome.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>

bool is_palindrome(const std::string& str)
{
    std::string cleanedStr(str);
    std::transform(cleanedStr.begin(), cleanedStr.end(), cleanedStr.begin(),
        [](const auto& el) -> char {
            if (std::isalpha(el)) {
                return std::tolower(el);
            }
            return ' ';
        });
    cleanedStr.erase(std::remove(cleanedStr.begin(), cleanedStr.end(), ' '), cleanedStr.end());
    return std::equal(cleanedStr.cbegin(), std::next(cleanedStr.cbegin(), cleanedStr.size() / 2), cleanedStr.crbegin());
}
