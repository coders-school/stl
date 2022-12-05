#include "CheckPalindrome.hpp"

bool is_palindrome(std::string & word) {
    for(auto n : word) {
        if (n == '\'') {
            word.erase(std::remove(word.begin(), word.end(), n), word.end());
        }
        if (n == ' ') {
            word.erase(std::remove(word.begin(), word.end(), n), word.end());
        }
        if (n == ',') {
            word.erase(std::remove(word.begin(), word.end(), n), word.end());
        }
        if (n == '!') {
            word.erase(std::remove(word.begin(), word.end(), n), word.end());
        }
        if (n == '?') {
            word.erase(std::remove(word.begin(), word.end(), n), word.end());
        }
        if (n == '-') {
            word.erase(std::remove(word.begin(), word.end(), n), word.end());
        }
        if (n == '.') {
            word.erase(std::remove(word.begin(), word.end(), n), word.end());
        }
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);   
    }
    std::reverse(std::begin(word), std::end(word));
    std::string word2 {};
    for(auto n : word) {
        word2.push_back(n);
    }
    std::reverse(std::begin(word), std::end(word));
    if(word == word2) {
        return true;
    }
    else
        return false;
}