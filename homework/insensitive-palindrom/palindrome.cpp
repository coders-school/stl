#include "palindrome.hpp"

#include <algorithm>
#include <locale>
#include <string>

bool is_palindrome(std::string words) {
    words.erase(std::remove_if(words.begin(), words.end(), [](const auto& elem){
        if (std::tolower(elem) < 'a' || std::tolower(elem) > 'z') {
            return true;
        } else {
            return false;
        }
    }), words.end());
    return std::equal(words.cbegin(),
                      words.cbegin() + words.size() / 2,
                      words.crbegin(),
                      [](const auto& letter1, const auto& letter2){
        if (std::tolower(letter1) == std::tolower(letter2)) {
            return true;
        } else {
            return false;
        }
    });
}
