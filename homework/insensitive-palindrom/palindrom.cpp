#include "palindrom.hpp"

bool is_palindrome(const std::string& str) {
    std::string alphaStr;
    std::string revStr;

    std::copy_if(str.begin(), str.end(), std::back_inserter(alphaStr), [](unsigned char c) { return std::isalpha(c); });
    std::transform(alphaStr.begin(), alphaStr.end(), alphaStr.begin(), [](unsigned char c) { return std::tolower(c); });
    revStr = alphaStr;
    std::reverse(revStr.begin(), revStr.end());
    
    return revStr == alphaStr;
}