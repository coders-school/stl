#include "vowel.hpp"
#include <algorithm>

void noVowelsInSentence (std::string& sentence){
    for (char vowel : {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'}){
    sentence.erase(std::remove(sentence.begin(), sentence.end(), vowel), sentence.end());
    }
}

void removeVowels (std::vector<std::string>& word){
    for (auto& elem : word){
        noVowelsInSentence(elem);
    }
}

