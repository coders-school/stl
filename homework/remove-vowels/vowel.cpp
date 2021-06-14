#include "vowel.hpp"

bool isVowel(char a){
    std::array<char, 12> vowel = {'a','e', 'i', 'o', 'u', 'y', 'A','E', 'I', 'O', 'U', 'Y'};
    for(auto vow : vowel){
        if (vow == a){
            return true;
        }
    }
    return false;
}

void removeVowels(std::vector<std::string> &vec){
    for(auto &v : vec){
        removeVowelsFromString(v);
    }
}

void removeVowelsFromString(std::string &str){
   std::string newString = "";
   for(auto &temp : str){
       if(!isVowel(temp)){
           newString += temp;
       }
   }
   str = newString;
}