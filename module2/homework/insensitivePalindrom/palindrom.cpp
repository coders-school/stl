#include "palindrom.hpp"

#include <algorithm>
#include <cctype>

bool is_palindrome(const std::string& sentence) {
    std::string toCheck = sentence;

    toCheck.erase(std::remove_if(toCheck.begin(), toCheck.end(), [](auto character) {
        return !isalnum(character);
    }), toCheck.end());

    std::transform(toCheck.begin(), toCheck.end(), toCheck.begin(), [](auto character) {
        return tolower(character);
    });

    return std::equal(toCheck.begin(), toCheck.begin() + toCheck.size()/2, toCheck.rbegin());       
}
