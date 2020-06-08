#include "vowel.hpp"

#include <algorithm>
#include <array>

void removeVowels(std::vector<std::string>& vec) {
    std::array<char, 12>
        vowels{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    std::sort(vowels.begin(), vowels.end());
    const auto predicate = [&vowels](const char letter) -> bool {
        return std::binary_search(vowels.cbegin(), vowels.cend(), letter);
    };

    for (auto& it : vec) {
        it.erase(std::remove_if(it.begin(), it.end(), predicate), it.end());
    }
}
