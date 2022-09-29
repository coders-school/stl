#include <map>

#include "vowel.hpp"

bool checkCharacterIfVowel(const char& c) {
    std::map<char, bool> vowels{
        {'A', true},
        {'E', true},
        {'I', true},
        {'O', true},
        {'U', true},
        {'Y', true},
    };
    return vowels.find(static_cast<char>(toupper(c)))->second;
}

void removeVowels(std::vector<std::string>& words) {
    std::string str;
    str.reserve(128);
    for (auto& word : words) {
        for (const char& c : word) {
            if (checkCharacterIfVowel(c)) {
                continue;
            }
            str.push_back(c);
        }
        word = str;
        str.clear();
    }
}
