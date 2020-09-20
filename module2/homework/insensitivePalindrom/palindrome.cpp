#include "palindrome.hpp"

#include <algorithm>

std::string preparingString(std::string& str) {
    std::for_each(begin(str), end(str), [](char& c) { c = ::tolower(c); });
    str.erase(std::remove_if(begin(str), end(str),
                             [](auto& c) { return (isalpha(c) ? false : true); }),
              end(str));
    return str;
}

bool is_palindrome(const std::string& text) {
    std::string copy;
    std::copy(begin(text), end(text), begin(copy));
    preparingString(copy);
    return std::equal(begin(copy), end(copy) + copy.size() / 2, rbegin(copy));
}
