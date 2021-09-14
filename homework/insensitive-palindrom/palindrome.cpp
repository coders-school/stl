#include "palindrome.hpp"
#include <algorithm>
#include <cctype>

bool is_palindrome(std::string text) {
    text.erase(std::remove_if(text.begin(), text.end(), [](unsigned char c)
                              { return isspace(c) || !isalpha(c); }),
               text.end());
    std::transform(text.begin(), text.end(), text.begin(), tolower);
    return std::equal(text.cbegin(), text.cend(), text.crbegin(), text.crend());
}
