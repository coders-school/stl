#include "palindrom.hpp"

std::string removeSpecialChar(std::string temp){
    std::string newString = "";
    for(const auto& ch : temp){
        if(std::isalnum(ch)){
            newString += std::tolower(ch);
        }
    }
    return newString;
}

bool is_palindrome(std::string temp){
    std::string newStr = removeSpecialChar(temp);
    for(int i = 0, k = newStr.size()-1 ; i < newStr.size()/2; i++,k--){
        if(newStr[i] != newStr[k]){
            return false;
        }
    }
    return true;
}