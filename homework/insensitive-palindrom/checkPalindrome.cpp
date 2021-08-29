#include "checkPalindrome.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

bool is_palindrome(std::string stringToTest) {
    std::transform(begin(stringToTest), end(stringToTest), begin(stringToTest), [](char c){ return std::tolower(c); });
    stringToTest.erase(std::remove_if(stringToTest.begin(), stringToTest.end(), [](char c){ return !isalnum(c); }), stringToTest.end());
    return std::equal(stringToTest.begin(), stringToTest.begin() + stringToTest.size()/2, stringToTest.rbegin() );
}git s