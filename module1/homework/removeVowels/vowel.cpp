#include "vowel.hpp"
#include <algorithm>
#include <array>

namespace {
constexpr std::array<char, 12> vowels{'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
}

void removeVowels(std::vector<std::string>& text) {
    for (auto& el : text) {
        el.erase(std::remove_if(std::begin(el), std::end(el), [](unsigned char c) {
                     return std::find(std::begin(vowels), std::end(vowels), c) != std::end(vowels);
                 }),
                 std::end(el));
    }
}
