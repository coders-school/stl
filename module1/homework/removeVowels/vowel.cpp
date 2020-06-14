#include "vowel.hpp"

#include <algorithm>

void removeVowels(std::vector<std::string>& words) {
    const std::string vowels = "aeiouyAEIOUY";

    for (auto& word : words) {
        for (const auto& letter : vowels) {
            word.erase(std::remove(word.begin(), word.end(), letter), word.end());
        }
    }
}
