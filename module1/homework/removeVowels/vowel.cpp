#include "vowel.hpp"

std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};

bool isVowel(char character) {
    return std::find(vowels.begin(), vowels.end(), character) != vowels.end();
}

void removeVowels(std::vector<std::string>& texts) {
    for (auto& text : texts) {
        text.erase(std::remove_if(text.begin(), text.end(), isVowel), text.end());
    }
}
