#include "vowel.hpp"

void removeVowels(std::vector<std::string>& sentence) {
    std::string vowels = "aeiouyAEIOUY";

    for (int i = 0; i < 12; i++) {
        for (auto& str : sentence) {
            str.erase(std::remove(str.begin(), str.end(), vowels[i]),
                      str.end());
        }
    }
}