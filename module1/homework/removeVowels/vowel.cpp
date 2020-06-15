#include "vowel.hpp"

#include <algorithm>

const std::string vowels{"aAeEiIoOuUyY"};

void removeVowels(std::vector<std::string>& vector) {
    for (auto& el : vector) {
        for (auto& vowel : vowels) {
            el.erase(std::remove(el.begin(), el.end(), vowel), el.end());
        }
    }
}
