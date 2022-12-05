#include "CheckPalindrome.hpp"

bool is_palindrome(std::string word) {
    
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    word.erase(std::remove_if(word.begin(), word.end(), [](auto x) {return !isalnum(x);})-word.begin());
    return std::equal(word.begin(), word.end(), word.rbegin());
}