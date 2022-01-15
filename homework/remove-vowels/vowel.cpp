#include "vowel.hpp"
#include <algorithm>
#include <string_view>

std::vector<std::string>& removeVowels(std::vector<std::string> &input)
{
    constexpr std::string_view vowels = "aAeEiIoOuUyY";
    for (auto& str : input)
        for (auto vowel : vowels)
            str.erase( remove( str.begin(), str.end(), vowel ), str.end() );

    return input;
}
