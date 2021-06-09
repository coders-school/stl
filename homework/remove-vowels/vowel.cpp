#include "vowel.hpp"

void removeVowels(std::vector<std::string>& words)
{
    for (auto &line : words)
    {
        line.erase(std::remove_if(line.begin(), line.end(), [](char scanChar)
                         { 
                            scanChar=std::tolower(scanChar);
                                if ( (scanChar=='a') || (scanChar=='e') || (scanChar=='i') || (scanChar=='o') || (scanChar=='u') || (scanChar=='u') || (scanChar=='y') ) {return true;};
                                   return false; }),
                   line.end());
    };
};