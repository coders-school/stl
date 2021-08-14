#include "palindrome.h"

bool is_palindrome(std::string word) {
    word.erase(std::remove_if(word.begin(), word.end(), [](auto c){
        return !std::isalnum(c);
    }), word.end());
    std::transform(word.begin(), word.end(), word.begin(), [](auto c){
        return std::tolower(c);
    });
    return std::equal(word.begin(), word.begin() + word.size() / 2, word.rbegin());
}