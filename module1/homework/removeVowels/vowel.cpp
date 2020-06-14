#include "vowel.hpp"

#include <algorithm>

void removeVowels(std::vector<std::string>& words){
    auto isVowel = [](char c){ return std::find(VOWELS.begin(), VOWELS.end(), c) != VOWELS.end(); };
    for(auto& word: words){
        word.erase(std::remove_if(word.begin(), word.end(), isVowel), word.end());
    }
}
