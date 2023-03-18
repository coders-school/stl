#include "PalindromTest.hpp"

bool is_palindrome(const std::string& input) {
    std::string removeChars = "?\"'\"-?!.,()[]/\u201C\u201D\u2019â\u0080\u009c,â\u0080\u009d â\u0080\u0099 â\u0080\u009d â\u0080\u0094 ";
    std::string newString = input;

    newString.erase(std::remove_if(newString.begin(), newString.end(), [&](const auto& el) { if(removeChars.find(el) != std::string::npos){ return true; } return false; }), newString.end());

    std::transform(newString.begin(), newString.end(), newString.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    std::string newStringReversed = newString;

    std::reverse(newStringReversed.begin(), newStringReversed.end());

    return std::equal(newString.begin(), newString.end(), newStringReversed.begin(), newStringReversed.end());
}