#include "vowel.hpp"

void removeVowels(std::vector<std::string>& words)
{
    for (auto &it : words)
    {
        it.erase(std::remove_if(it.begin(), it.end(), [](char scanChar)
                         { 
                            scanChar=std::tolower(scanChar);
                                if ( (scanChar=='a') || (scanChar=='e') || (scanChar=='i') || (scanChar=='o') || (scanChar=='u') || (scanChar=='u') || (scanChar=='y') ) 
                                {
                                    return true;
                                };
                                   return false; 
                                   }),
                   it.end());
    };
};
