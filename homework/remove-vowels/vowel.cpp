#include "vowel.hpp"

void removeVowels(expressions &vec)
{
    for (auto& str: vec)
    {
        size_t pos = str.find_first_of("aeiouyAEIOUY");
        while (pos != std::string::npos)
        {
            str.erase(pos, 1);
            pos = str.find_first_of("aeiouyAEIOUY", pos);
        }
    }
}