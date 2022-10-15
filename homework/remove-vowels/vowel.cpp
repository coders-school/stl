#include "vowel.hpp"
#include "array"

std::vector<std::string> removeVowels(std::vector<std::string>& vec) {
    std::array<char, 12> vowels{'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};

    for (auto& element : vec) {
        for (auto vowel : vowels) {
            auto i = std::remove(element.begin(), element.end(), vowel);
            element.erase(i, element.end());
        }
    }

    return vec;
}
