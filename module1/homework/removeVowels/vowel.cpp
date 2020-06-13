#include "vowel.hpp"

#include <algorithm>
#include <array>

void removeVowels(std::vector<std::string>& text) {
    constexpr std::array<char, 12> vowels{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};

    for (auto& el : text) {
        el.erase(std::remove_if(std::begin(el),
                                std::end(el),
                                [&vowels](unsigned char c) {
                                    return std::find(std::cbegin(vowels),
                                                     std::cend(vowels),
                                                     c) != std::cend(vowels);
                                }),
                 std::end(el));
    }
}
