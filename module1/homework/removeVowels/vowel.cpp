#include "vowel.hpp"

#include <algorithm>

const std::string vowels{"aAeEiIoOuUyY"};

void removeVowels(std::vector<std::string>& vector) {
    for (std::string& el : vector) {
        for (char vowel : vowels) {
            el.erase(std::remove(el.begin(), el.end(), vowel), el.end());
        }
    }
}
