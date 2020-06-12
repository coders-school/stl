#include "vowel.hpp"
#include <algorithm>
#include <iostream>


void removeVowels(std::vector<std::string>& someText)
{
    //const std::string vowels{"AEIOUYaeiouy"};
    const std::string vowels{"AEIOUY"};

    for (std::string& words : someText)
    {
        words.erase(
            remove_if(words.begin(), words.end(), [vowels](char c)
            {
                return vowels.end() != find(vowels.begin(), vowels.end(), std::toupper(c));
            }), 
            words.end()
        );         
    }
}
