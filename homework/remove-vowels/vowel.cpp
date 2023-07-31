#include "vowel.hpp"

void removeVowels(std::vector<std::string>& vec)
{     
    for (auto& el : vec) {   
        el = removeLetter(el, 'a', 'A');
        el = removeLetter(el, 'e', 'E');
        el = removeLetter(el, 'i', 'I');
        el = removeLetter(el, 'o', 'O');
        el = removeLetter(el, 'u', 'U');
        el = removeLetter(el, 'y', 'Y');
    }
};

std::string removeLetter(std::string& str, const char lowerCaseLetter, const char upperCaseLetter)
{         
    str.erase(std::remove(str.begin(), str.end(), lowerCaseLetter), str.end());
    str.erase(std::remove(str.begin(), str.end(), upperCaseLetter), str.end());
    return str;
}
