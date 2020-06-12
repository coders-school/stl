#include "vowel.hpp"

#include <array>
#include <iostream>
#include <algorithm>

void removeVowels (std::vector<std::string>& fullText) {

    const std::array<char,12> vowelArr {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};

    for (auto& element : fullText) {
        for (const auto& vowel : vowelArr) {
        element.erase(std::remove(element.begin(), element.end(), vowel),
                    element.end());
        }
    }
}
