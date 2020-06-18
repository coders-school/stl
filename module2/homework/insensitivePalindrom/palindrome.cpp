#include "palindrome.hpp"

#include <algorithm>
#include <cctype>

void deleteSpecialChar(std::string& str) {
    str.erase(std::remove_if(begin(str), end(str), [](const auto& character) { return !(std::isalpha(character)); }), end(str));
}

void doLowerCase(std::string& str) {
    std::transform(begin(str), end(str), begin(str), [](auto& letter) { return std::tolower(letter); });
}

bool isPalindrome(const std::string& str) {
    std::string strToCheck = str;
    deleteSpecialChar(strToCheck);
    doLowerCase(strToCheck);
    return std::equal(begin(strToCheck), begin(strToCheck) + strToCheck.size() / 2, rbegin(strToCheck));
}
