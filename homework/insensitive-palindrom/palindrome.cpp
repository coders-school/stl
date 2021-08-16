#include "palindrome.hpp"

#include <algorithm>
#include <ctype.h>
#include <iostream>

bool is_palindrome(std::string sentence) {
    std::transform(sentence.begin(), 
                   sentence.end(), 
                   sentence.begin(),
                   [](auto& el) { return isalpha(el) ? std::tolower(el) : el = 'Q'; });
    sentence.erase(std::remove(begin(sentence), end(sentence), 'Q'), end(sentence));
    return std::equal(begin(sentence), begin(sentence) + sentence.size() / 2, rbegin(sentence));
}