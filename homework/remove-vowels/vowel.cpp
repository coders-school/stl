#include "vowel.hpp"

void removeVowels(std::vector<std::string> &words) {
    const std::string vowels = {"AEIOUYaeiouy"};
    for (auto &word : words) {
        for (auto vowel : vowels) {
            word.erase(std::remove(word.begin(), word.end(), vowel),word.end());
        }
    }
}