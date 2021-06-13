#include "vowel.hpp"
#include <array>

bool isVowel(const char letter) {
    static constexpr std::array vowelArr{'a', 'A', 'e', 'E', 'i', 'I', 'u', 'U', 'o', 'O', 'y', 'Y'};

    return std::find(vowelArr.cbegin(), vowelArr.cend(), letter) != vowelArr.cend();
}

void removeVowels(std::vector<std::string>& words) {
    for (auto& el : words) {
        el.erase(std::remove_if(el.begin(), el.end(), isVowel), el.end());
    }
}
