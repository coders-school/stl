#include "vowel.hpp"

#include <algorithm>

void removeVowels(std::vector<std::string>& vec) {
    std::string vowels("AEIOUYaeiouy");

    for (auto& words : vec) {
        for (const auto& element : vowels) {
            words.erase(std::remove(words.begin(), words.end(), element), words.end());
        }
    }
}