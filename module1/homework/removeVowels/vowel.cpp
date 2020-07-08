#include "vowel.hpp"

#include <algorithm>
#include <array>

void removeVowels(std::vector<std::string>& vectorOfSentences) {
    std::array<char, 12> vowelsArr{'a', 'e', 'i', 'u', 'y', 'o', 'A', 'E', 'I', 'U', 'Y', 'O'};

    for (auto& sentence : vectorOfSentences) {
        auto remove = std::remove_if(sentence.begin(), sentence.end(),
                                     [&vowelsArr](auto& vowel) {
                                         if (std::find(vowelsArr.begin(), vowelsArr.end(), vowel) != vowelsArr.end()) {
                                             return true;
                                         }
                                         return false;
                                     });
        sentence.erase(remove, sentence.end());
    }
}