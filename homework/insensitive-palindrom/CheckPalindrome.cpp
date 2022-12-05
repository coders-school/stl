#include "CheckPalindrome.hpp"


bool is_palindrome(std::string str) {
    std::for_each(str.begin(), str.end(), [](char & c){c = ::tolower(c);});
    str.resize(std::remove_if(str.begin(), str.end(),[](char x){return !isalnum(x);})-str.begin());
    return std::equal(str.begin(), str.end(), str.rbegin());
}
