#include "vowel.hpp"

#include <algorithm>
#include <array>

void removeVowels(std::vector<std::string>& words)
{
    constexpr size_t size = 12;
    const std::array<char, size> vowels = { 'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y' };
    
    for(auto& word : words)
    {
       for(const auto& letter : vowels)
       {
           word.erase(std::remove(word.begin(), word.end(), letter), word.end());
       }
    }
}
