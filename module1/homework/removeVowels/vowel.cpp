#include "vowel.hpp"

#include <algorithm>

void removeVowels(std::vector<std::string>& vec) {
    const std::vector<char> vowelVector{'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};
    for (auto& element : vec) {
        for (const auto& vowel : vowelVector) {
            element.erase(std::remove(element.begin(), element.end(), vowel), element.end());
        }
    }
}
