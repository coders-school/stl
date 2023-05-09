#include "vowel.hpp"
void removeVowels(std::vector<std::string>& words)
{
    std::array<const char,12> vowels {'a','e','i','o','u','y','A','E','I','O','U','Y'};
    std::vector<std::string>::iterator it;
    std::array<const char,12>::iterator it1;
    for(it = words.begin(); it != words.end(); it++)
    {
        for(it1 = vowels.begin(); it1!=vowels.end();it1++)
        {
            it->erase(std::remove(it->begin(),it->end(),*it1),it->end());
        }
    }
}