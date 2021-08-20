#include "insensitivePalindrom.hpp"
#include <algorithm>
#include <cctype>

bool is_palindrome(const std::string& palindrome) {
    std::string removedSigns;
    std::copy_if(palindrome.begin(), palindrome.end(), std::back_inserter(removedSigns), [](unsigned char ch){ return std::isalnum(ch);});
    std::transform(removedSigns.begin(), removedSigns.end(), removedSigns.begin(), [](auto& ch){return std::tolower(ch);});
    if (std::mismatch(removedSigns.begin(), removedSigns.end(), removedSigns.rbegin()) == std::make_pair(removedSigns.end(), removedSigns.rend())) {
        return true;
    }
    return false;
}