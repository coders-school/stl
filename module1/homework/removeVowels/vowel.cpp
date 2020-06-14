#include "vowel.hpp"
#include <algorithm>

void removeVowelsFromString (std::string& sentence){
    for (auto vowel : allVowels){
    sentence.erase(std::remove(sentence.begin(), sentence.end(), vowel), sentence.end());
    }
}

void removeVowels (std::vector<std::string>& word){
    for (auto& elem : word){
        removeVowelsFromString(elem);
    }
}
