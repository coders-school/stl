#include "vowel.hpp"
#include <algorithm>
#include <iostream>

std::vector<std::string>& removeVowels(std::vector<std::string>& vs) {
    auto char_is_not_vowel = [](char x) {
        std::string vowels = "AEIOUYaeiouy";
        bool char_is_vowel = (std::find(vowels.begin(), vowels.end(), x) != vowels.end());
        return not char_is_vowel;
    };

    auto get_str_without_vowels = [&](const std::string& s) {
        std::string output = "";
        for (const auto& x : s) {
            if (char_is_not_vowel(x)) {
                output += x;
            }
        }
        return output;
    };

    std::transform(vs.cbegin(), vs.cend(),
                   vs.begin(),
                   [&](std::string s) {
                       return get_str_without_vowels(s);
                   });

    return vs;
}