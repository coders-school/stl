#include "vowel.hpp"
 
bool isVowel(const char& letter) {
    char vowels[12] = {'a','A','e','E','i','I','o','O','u','U','y','Y'};
    for (const auto& el : vowels) {
       if (letter == el){
          return true;     
       }
    }
    return false;
}
 
void removeVowels(std::vector<std::string>& words) {
    for (auto& el : words) {
        el.erase(std::remove_if(el.begin(), el.end(), isVowel), el.end());
    }
}

