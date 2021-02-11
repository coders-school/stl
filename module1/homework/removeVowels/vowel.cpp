#include "vowel.hpp"

void removeVowels(std::vector<std::string>& vec) {
    bool isVowel = [](char c) { return std::find(VOWELS.begin(), VOWELS.end(), c) != VOWELS.end(); };
    for (auto& word : vec) {
        word.erase(std::remove_if(word.begin(), word.end(), isVowel), word.end());
    }
}