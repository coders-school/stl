#include <algorithm>
#include <array>
#include "vowel.hpp"

bool isVowel(char character) {
    character = std::tolower(character);
    for (const auto vowel : { 'a', 'e', 'i', 'o', 'u', 'y' }) {
        if (character == vowel) {
            return true;
        }
    }
    return false;
}

void removeVowels(std::vector<std::string>& input) {
    for (auto& str : input) {
        auto removeCondition = [](char character) { 
            return isVowel(character); 
        };
        auto removeIterator = std::remove_if(str.begin(), str.end(), removeCondition);
        str.erase(removeIterator, str.end());
    }
}

