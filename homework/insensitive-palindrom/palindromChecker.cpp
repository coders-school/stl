#include "palindromChecker.hpp"

#include <algorithm>
#include <cctype>

bool is_palindrome(std::string word) {

    auto newEnd = std::remove_if(word.begin(), word.end(), [](auto c){ 
        if(std::isalnum(c)){
            return false;
        }
        return true; 
    });

    std::transform(word.begin(), newEnd,
                   word.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    return std::equal(word.begin(), newEnd, word.rbegin() + (word.end() - newEnd), word.rend());
}
