#include "vowel.hpp"

#include <algorithm>

void removeVowels(std::vector<std::string>& vecOfWords) {
    std::string vowels("aeyioąęuóAEYIOĄĘUÓ");

    for (auto& element : vecOfWords) {
        for (auto vowel : vowels) {
            element.erase(std::remove(element.begin(), element.end(), vowel), element.end());
        }
    }
}
