#include "vowel.hpp"

#include <algorithm>

const std::string vowels = "aeiouyAEIOUY";

void removeVowels(std::vector<std::string>& vectorOfStrings) {
    for (auto& str : vectorOfStrings) {
        str.erase(std::remove_if(str.begin(), str.end(), [](const char charChecked) {
                      return std::any_of(vowels.begin(), vowels.end(), [=](const char vowel) {
                          return charChecked == vowel;
                      });
                  }),
                  str.end());
    }
}
