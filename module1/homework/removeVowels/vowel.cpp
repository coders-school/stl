#include "vowel.hpp"
#include <iostream>

std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};

bool isVowel(char &character)
{
    if (std::find(vowels.begin(), vowels.end(), character) != vowels.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void removeVowels(std::vector<std::string> &texts)
{
    for (auto &text : texts)
    {
        std::string textWithoutVowels = "";

        for (auto &character : text)
        {
            if (!isVowel(character))
            {
                textWithoutVowels += character;
            }
        }

        text = textWithoutVowels;
    }
}
