#include "vowel.hpp"

void removeVowels(std::vector<std::string> & words){
    //const std::string vowels = {"aeiouyAEIOUY"};
    constexpr const char vowels[] = {"aeiouyAEIOUY"};

    for (std::string & str : words){
        for (char sign : vowels){
            str.erase(std::remove(str.begin(), str.end(), sign), str.end());
        }
    }
}
