#include "vowel.hpp"
std::vector<char> Vowels={'a','o','e','i','u','y','A','O','E','I','U','Y'};
bool isVowel(const char & ch)
{
    bool ifIsVowel{false};
    for(auto &n: Vowels)
    {
        if(ch == n)  
            return true;    
    }
    return ifIsVowel;
}
void removeVowels(std::vector<std::string> &text)
{
    for(size_t i = 0; i < text.size(); i++)
    {
        std::string &sentence = text.at(i);
        for(size_t letterPos = 0; letterPos < sentence.size(); letterPos++)
        {
            if(isVowel(sentence.at(letterPos)))
            {
                sentence.erase(letterPos,1);
                letterPos--;
            }
            
        }
    }
}


