#include "vowel.hpp"

std::string allVow {"aeiouyAEIOUY"};

std::vector<std::string> removeVowels(std::vector<std::string>& vow) {
    std::for_each(vow.begin(), vow.end(), [](std::string& str)
    {
        str.erase(std::remove_if(str.begin(), str.end(), [](const char& ch)
        {
            return allVow.find(ch) != std::string::npos;
        }),
        str.end());
    });
    return vow;
}
