#include "palindrome.hpp"

#include <algorithm>
#include <cctype>

std::string deleteSpecialChar(std::string& str) {
    str.erase(std::remove_if(begin(str), end(str), [](const auto& character) { return !(std::isalpha(character)); }), end(str));
    return str;
}

std::string doLowerCase(std::string& str) {
    std::transform(begin(str), end(str), begin(str), [](auto& letter) { return std::tolower(letter); });
    return str;
}

bool is_palindrome(std::string& str) {
    std::string strToCheck = deleteSpecialChar(str);
    doLowerCase(strToCheck);
    return std::equal(begin(strToCheck), begin(strToCheck) + strToCheck.size() / 2, rbegin(strToCheck));
}
