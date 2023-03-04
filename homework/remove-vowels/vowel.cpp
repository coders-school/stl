#include "vowel.hpp"
#include <algorithm>


auto isVowel (char c, const std::array<char, 6>& vowels){
    return std::find(vowels.begin(), vowels.end(), c) != vowels.end();
}

void removeVowels(std::vector<std::string> &list){

  std::array<char, 6> arr = {'a', 'e', 'i', 'o', 'u', 'y'};

  for (auto& str : list){
        str.erase(std::remove_if(str.begin(), str.end(),
                             [&](char c) { return isVowel(c, arr); }),
              str.end());
  }

 
}
