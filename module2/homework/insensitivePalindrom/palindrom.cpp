#include "palindrom.hpp"

#include <algorithm>

bool is_palindrome(std::string stringToCheck) {
    stringToCheck.erase(std::remove_if(stringToCheck.begin(),
                                       stringToCheck.end(),
                                       [](char partOfString) { return !std::isalpha(partOfString); }),
                        stringToCheck.end());
    std::transform(stringToCheck.begin(), stringToCheck.end(), stringToCheck.begin(), ::tolower);
    return (std::equal(stringToCheck.begin(), stringToCheck.begin() + stringToCheck.size() / 2, stringToCheck.rbegin()));
}
