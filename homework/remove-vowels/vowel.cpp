#include "vowel.hpp"
#include <array>
#include <algorithm>

void removeVowels(std::vector<std::string>& stringsVector) {
    // I'm using array of chars instead of C-style string to avoid having null terminator in my array
    constexpr std::array vowels{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for(auto& string : stringsVector) {
        for(auto& character : vowels) {
            string.erase(std::remove(string.begin(), string.end(), character), string.end());
        }
    }
}
