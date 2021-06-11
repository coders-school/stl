#include "vowel.hpp"
#include <algorithm>
#include <array>

void removeVowels(std::vector<std::string>& stringsVector) {
    // I'm initializing vowels using separate chars rather than string literal to avoid null terminator
    constexpr std::array vowels{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for (auto& string : stringsVector) {
        for (const auto& character : vowels) {
            string.erase(std::remove(string.begin(), string.end(), character), string.end());
        }
    }
}
