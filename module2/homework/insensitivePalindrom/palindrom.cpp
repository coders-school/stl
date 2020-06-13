#include "palindrom.hpp"

#include <algorithm>
#include <cctype>

bool is_palindrome(std::string inputStr) {
    inputStr.erase(std::remove_if(inputStr.begin(),
                                  inputStr.end(),
                                  [](auto strElement) { return !std::isalpha(strElement); }),
                   inputStr.end());

    std::transform(inputStr.begin(), inputStr.end(), inputStr.begin(),
                   [](auto strElement) { return std::tolower(strElement); });

    auto pairIterator = std::mismatch(inputStr.begin(), inputStr.end(), inputStr.rbegin());

    return (pairIterator.first == inputStr.end() && pairIterator.second == inputStr.rend());
}
