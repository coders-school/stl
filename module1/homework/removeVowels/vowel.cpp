#include "vowel.hpp"

namespace {
const std::string vowels = "AEIOUYaeiouy";
}

void removeVowelFromString(std::string& str) {
    for (const auto& vowel : vowels) {
        str.erase(std::remove(str.begin(), str.end(), vowel), str.end());
    }
}

void removeVowels(std::vector<std::string>& vec) {
    for (auto& el : vec) {
        removeVowelFromString(el);
    }
}
