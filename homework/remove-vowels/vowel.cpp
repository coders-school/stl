#include "vowel.hpp"

bool isVowel(char check){
    std::vector<char> vowels = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y'};
    for (auto &vowel : vowels){
        if (check == vowel){
            return true;
        }
    }
    return false;
}

void removeVowels(std::vector<std::string> & words){
    for (auto &word : words){
        for (auto i = word.begin(); i <= word.end(); i++){
            while(isVowel(*i)){
                word.erase(i);
            }
        }
    }
}

