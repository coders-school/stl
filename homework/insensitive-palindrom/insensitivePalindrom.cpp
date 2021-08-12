#include "insensitivePalindrom.hpp"

#include <algorithm>
#include <cctype>

#include <iostream>

bool is_palindrome(const std::string& textToCheck) {
    std::string tempText{};
    std::copy_if(begin(textToCheck), 
                 end(textToCheck), 
                 std::back_inserter(tempText), 
                 [](auto ele){ 
                     return std::isalpha(ele); 
                 });
    return std::equal(begin(tempText), 
                      begin(tempText) + tempText.size()/2, 
                      rbegin(tempText), [](auto a, auto b){ 
                          return std::tolower(a) == std::tolower(b);
                      });
}