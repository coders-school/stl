#include "is_palindrome.hpp"
bool is_palindrome(std::string text) {
    std::string temp = "";
    text.erase(std::remove_if(text.begin(), text.end(), [](unsigned char c) { return !isalnum(c); }), text.end());
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) { return std::tolower(c); });
    temp = text;
    std::reverse(temp.begin(), temp.end());

    if (temp == text) {
    	 return true;
    }

    return false;
}
