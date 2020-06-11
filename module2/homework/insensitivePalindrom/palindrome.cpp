#include "palindrome.hpp"

#include <algorithm>
#include <cctype>

bool is_palindrome(const std::string& str) {
    std::string temp;
    std::copy_if(str.begin(), str.end(), std::back_inserter(temp), [](const auto& sign){
            return std::isalpha(sign);
    });
    std::transform(temp.begin(), temp.end(), temp.begin(), [](const auto& letter){
            return std::tolower(letter);
    });
    
    return std::equal(temp.begin(), temp.begin() + temp.size() / 2, temp.rbegin());
}
