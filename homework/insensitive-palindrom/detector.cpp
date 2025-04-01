#include "detector.hpp"
#include <algorithm>

void tolowercase(std::string& word){
    std::transform(word.begin(), word.end(), word.begin(), [](char c){
        return std::tolower(c);
    });
}

void removeSpecialCases(std::string& word){
    word.erase(std::remove_if(word.begin(), word.end(), [](char c){
        return !std::isalnum(c);
    }), word.end());
}

bool is_palindrome(std::string word){
    tolowercase(word);
    removeSpecialCases(word);
    auto begin = word.begin();
    auto end = word.rbegin();

    while(begin < word.end() - (word.size() / 2)){ 
        if(*begin == *end){ 
            begin = std::next(begin);
            end = std::next(end);
        } else{
            return false;
        }
    }
    return true;
}