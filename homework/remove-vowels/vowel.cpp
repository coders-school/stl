#include "vowel.hpp"
#include <algorithm>

constexpr auto vowels = {'a', 'i', 'u', 'e', 'o', 'y',
                         'A', 'I', 'U', 'E', 'O', 'Y'};

bool isVowel(const char& letter) noexcept {
    for (const auto& vowel : vowels) {
        if (letter == vowel) {
            return true;
        }
    }
    return false;
}

void removeVowels(std::string& text) {
    text.erase(
        std::stable_partition(begin(text), end(text),
                              [](const char& letter) {
                                  return !isVowel(letter);
                              }),
        text.end());
}

void removeVowels(std::vector<std::string>& textVector) {
    for (auto& text : textVector) {
        removeVowels(text);
    }
}
