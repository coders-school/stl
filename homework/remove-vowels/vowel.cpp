#include "vowel.hpp"

#include <array>
#include <algorithm>

void removeVowels(std::vector<std::string>& vec)
{
    constexpr std::array<char, 12> vowels {
        'a', 'e', 'i', 'o', 'u','y',
        'A', 'E', 'I', 'O', 'U', 'Y'
    };

    for (auto& str : vec)
    {
        for (size_t i=0; i < str.size(); ++i)
        {
            // Try find a string's letter in our vowels 
            auto it = std::find(vowels.begin(), vowels.end(), str[i]);

            if (it != vowels.end())
            {
                // if we find it we have to remove it,
                // after this we should decrement our iterator because we erase one element
                // It makes sure that our iterator iterate over all letters
                str.erase(std::find(str.begin(), str.end(), *it));
                --i;
            }
        }
    }
}