#include "palindrome.hpp"

#include <algorithm>
#include <cctype>

bool is_palindrome(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), [](auto ch) { return std::tolower(ch); });
    str.erase(std::remove_if(str.begin(), str.end(), [](char ch) { return !((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)); }), str.end());

    return std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin());
}
