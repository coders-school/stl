#include "palindrome.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <ranges>

bool is_palindrome(std::string word_to_check)
{
    std::ranges::for_each(word_to_check, [](char& letter) {
        letter = std::tolower(letter);
    });
    std::string w = word_to_check;
    w.erase(std::remove_if(w.begin(), w.end(),
                [](char& letter) {
                    return !(std::isalnum(letter));
                }),
        w.end());
    std::string r_w = w;
    std::ranges::reverse(r_w);
    return w == r_w;
}