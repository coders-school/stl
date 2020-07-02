#include "vowel.hpp"

void removeVowels(std::vector<std::string> &strings)
{
    constexpr std::array<char, vowels_number> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for (auto &word : strings)
        for (auto &characterToErase : vowels)
            word.erase(std::remove(word.begin(), word.end(), characterToErase), word.end());
}
