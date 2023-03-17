#include "PalindromTest.hpp"

bool PalindromTest::is_palindrome(const std::string& input) {
    std::string removeChars = ",.?()[] ";
    std::string newString = input;
    newString.erase(std::remove_if(newString.begin(), newString.end(), [&](const auto& el) { if(removeChars.find(el) != std::string::npos){ return true; } return false; }));
    std::transform(newString.begin(), newString.end(), newString.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    std::string newStringReversed = newString;

    std::reverse(newStringReversed.begin(), newStringReversed.end());
    return std::equal(newString.begin(), newString.end(), newStringReversed.begin(), newStringReversed.end());
}