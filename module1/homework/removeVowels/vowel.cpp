#include "vowel.hpp"

#include <algorithm>
#include <array>

constexpr std::array<char, 12> vowels {'a','A','e','E','i','I','o','O','u','U','y','Y'};

void removeVowels(std::vector<std::string>& vec){
   for (auto& it : vec) {
      it.erase(std::remove_if(it.begin(),it.end(),
                                 [](auto c) {
                                    return std::any_of(vowels.begin(), vowels.end(), [c](auto vow) {
                                       return vow == c;
                                 });
                              }),
               it.end());
    }
}
