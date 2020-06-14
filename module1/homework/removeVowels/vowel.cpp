#include "vowel.hpp"

#include <algorithm>

std::string vowels{"aAeEiIoOuUyY"};

void removeVowels(std::vector<std::string>& vector) {
    for (auto& el : vector) {
        for (auto& vowel : vowels) {
            auto it = std::remove(el.begin(), el.end(), vowel);
            el.erase(it, el.end());
        }
    }
}
