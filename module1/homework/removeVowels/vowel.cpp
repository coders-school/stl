#include "vowel.hpp"

#include <algorithm>

void removeVowels(std::vector<std::string>& data) {
    std::string vowels("AaĄąEeĘęIiOoÓóUuYy");

    for (auto& entry : data) {
        for (auto vowel : vowels) {
            entry.erase(std::remove(entry.begin(), entry.end(), vowel), entry.end());
        }
    }
}
