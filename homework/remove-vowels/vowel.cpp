#include "vowel.hpp"

void removeVowels(std::vector<std::string> & vec_string)
{
    const std::string vowel_string("aeiouyAEIOUY");

    for (auto & el : vec_string)
    {
        for (auto & el_char : vowel_string)
        {
            el.erase(std::remove(el.begin(), el.end(), el_char), el.end());
        }
    }
}