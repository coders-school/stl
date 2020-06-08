#include "vowel.hpp"

#include <algorithm>


void removeVowels(std::vector<std::string>& strings) {
    constexpr char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};

    for (auto& str : strings) {
        str.erase(std::remove_if(str.begin(), str.end(),
                                 [&](const auto c) {
                                     return std::find(std::cbegin(vowels), std::cend(vowels), c) != std::cend(vowels);
                                 }),
                  str.end());
    }
}
