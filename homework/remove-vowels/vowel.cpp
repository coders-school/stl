#include "vowel.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <array>

void removeVowels(std::vector<std::string>& vec) {
    constexpr std::array<char, 12> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for (auto &element: vec) {
        for (const auto &ch: vowels) {
            element.erase(std::remove(element.begin(), element.end(), ch), element.end());    
        }
    }
}