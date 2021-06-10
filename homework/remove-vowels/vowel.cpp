#include "vowel.hpp"

void removeVowels(std::vector<std::string>& words) {
    std::string vowels = "aeiouyAEIOUY";
    for (int i = 0; i < vowels.length(); i++) {
        for (auto& el : words) {
            el.erase(std::remove(el.begin(), el.end(), vowels[i]), el.end());
        }
    }
}
