//ignore special chars like ,.?()[], upper letters, spaces or endl
#include "palindrome.hpp"
#include <algorithm>
#include <iostream>
#include <ranges>

bool is_palindrome(std::string word_to_check){
    std::string reversed_word = word_to_check;
    std::ranges::reverse(word_to_check);
    return word_to_check == reversed_word;
}