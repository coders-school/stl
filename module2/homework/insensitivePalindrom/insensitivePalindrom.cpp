#include "insensitivePalindrom.hpp"

#include <algorithm>

bool is_palindrome(std::string text){
   text.erase(std::remove_if(text.begin(), text.end(),
                              [](auto character){
                                 return !std::isalpha(character);
                              }),
                              text.end());
std::transform(text.begin(), text.end(), text.begin(), ::tolower);
auto result = text;
std::reverse(text.begin(), text.end());
return text == result;

   
}
