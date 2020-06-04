#include "vowel.hpp"
#include <algorithm>

void removeVowels(std::vector<std::string>& vs) {
    constexpr char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};

    for (auto& str : vs) {
        str.erase(std::remove_if(
                      str.begin(), str.end(),
                      [&](char c) { return std::find(std::begin(vowels), std::end(vowels), c) != std::end(vowels); }),
                  str.end());
    }
}
