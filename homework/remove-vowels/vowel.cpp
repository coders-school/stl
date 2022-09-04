#include "vowel.hpp"

void removeVowels(std::vector<std::string>& words) {
    std::array vowels = {'a', 'e', 'y', 'i', 'o', 'u'};

    for (std::string& sentence : words) {
        sentence.erase(std::remove_if(sentence.begin(), sentence.end(), [&vowels](const char letter) {
                           return std::find(std::begin(vowels), std::end(vowels), std::tolower(letter)) != std::end(vowels);
                       }),
                       sentence.end());
    }
}
