#include <algorithm>
#include <cctype>
#include "palindrome.hpp"

bool is_palindrome(std::string str) {
    str.erase(std::remove_if(str.begin(), str.end(), 
                    [](unsigned char c){
                    return isspace(c) || !isalpha(c); }),      
                    str.end());
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    return std::equal(str.cbegin(), str.cend(), str.crbegin(), str.crend());
}