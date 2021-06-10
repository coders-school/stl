#include "vowel.hpp"

void removeVowels(std::vector<std::string>& words)
{
    for(auto & word : words){
        size_t vowel = word.find_first_of("aeiouyAEIOUY");
        while(vowel != std::string::npos)
        {
            word.erase(vowel, 1);
            vowel = word.find_first_of("aeiouyAEIOUY", vowel);
        }
    }
}

