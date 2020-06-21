#include "palindrome.hpp"
#include <algorithm>


bool is_palindrome(std::string str){

str.erase(std::remove_if(str.begin(), str.end(), [](char letter) { return std::isalpha(letter) == 0; }), str.end());
std::transform(str.begin(), str.end(), str.begin(), [](auto letter){return std::tolower(letter);});

return str == std::string(str.rbegin(), str.rend());
}

