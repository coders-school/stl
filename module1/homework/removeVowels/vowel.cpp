#include "vowel.hpp"
#include <algorithm>
#include <array>

constexpr std::array<char, 12> vowels{'a', 'e', 'i', 'o', 'u', 'y',
                                      'A', 'E', 'I', 'O', 'U', 'Y'};

void removeVowels(std::vector<std::string>& vec) {
    for (auto& el : vec) {
        el.erase(std::remove_if(el.begin(),
                                el.end(),
                                [](auto c) {
                                    return std::any_of(vowels.begin(), vowels.end(), [c](auto vow) {
                                        return vow == c;
                                    });
                                }),
                 el.end());
    }
}
