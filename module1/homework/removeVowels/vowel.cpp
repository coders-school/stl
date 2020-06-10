#include "vowel.hpp"

void removeVowelFromString(std::string& str) {
    const std::string vowels = "AEIOUYaeiouy";
    for (const auto& vowel : vowels) {
        str.erase(std::remove(str.begin(), str.end(), vowel), str.end());
    }
}

void removeVowels(std::vector<std::string>& vec) {
    for (auto& el : vec) {
        removeVowelFromString(el);
    }
}
