#include "vowel.hpp"

void removeVowels(std::vector<std::string>& vec)
{
    std::array<char, 12> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};
    for(int i = 0; i < vec.size(); i++)
    {
        for(auto vowel : vowels)
        {
            auto it = std::remove(vec[i].begin(), vec[i].end(), vowel);
            vec[i].erase(it, vec[i].end());
        }   
    }
}
