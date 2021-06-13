#include "vowel.hpp"

void removeVowels(std::vector<std::string>& vec) {
    std::vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};

    for (auto& it : vec) {
        for (auto& vowel : vowels)
            it.erase(std::remove(it.begin(), it.end(), vowel), it.end());
        for (auto& vowel : vowels)
            it.erase(std::remove(it.begin(), it.end(), toupper(vowel)), it.end());
    }
}