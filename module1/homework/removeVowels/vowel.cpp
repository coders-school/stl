#include "vowel.hpp"
#include <algorithm>

bool isVowel(char c){
     c = tolower(c);
     return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}
  
void removeVowels(std::vector<std::string>& words){
      for(auto& str : words){
         auto iter = std::remove_if(str.begin(), str.end(), isVowel);
         str.erase(iter, str.end());
     }
}
