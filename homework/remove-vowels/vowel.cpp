#include "vowel.hpp"

#include <algorithm>
void removeVowels(std::vector<std::string>& vec) {
    std::string vowels{"aeiouyAEIOUY"};
    for (auto& str : vec) {
        str.erase(std::remove_if(str.begin(),
                                 str.end(),
                                 [&vowels](const char c) {
                                     return std::string(vowels).find(c) !=
                                            std::string::npos;
                                 }),
                  str.end());
    };
}