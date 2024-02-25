#include "palindrom.hpp"

std::string removeSpecificChars(std::string& str, const std::string& charsToRemove) {
    for (char c : charsToRemove) {
        str.erase(std::remove(str.begin(), str.end(), c), str.end());
    }
    return str;
}

bool is_palindrome(const std::string& neo) {
    std::string str;
    std::copy(neo.cbegin(), neo.cend(), std::back_inserter(str));

    removeSpecificChars(str, charsToRemove);
    str.erase(std::remove_if(str.begin(), str.end(), ispunct), str.end());
    str.erase(std::remove_if(str.begin(), str.end(), isblank), str.end());
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    
    return std::equal(str.cbegin(), str.cbegin() + str.size() / 2, str.crbegin());
}
