#include "palindrome.hpp"
#include <ctype.h>
#include <algorithm>
#include <iostream>

bool is_palindrome(std::string sentence) {
    std::transform(sentence.begin(), sentence.end(), sentence.begin(),
                   [](auto& el) {
                       if (isalpha(el)) {
                           el = std::tolower(el);
                           return el;
                       }
                       el = 'Q';
                       return el;
                   });
    sentence.erase(std::remove(begin(sentence), end(sentence), 'Q'), end(sentence));

    return std::equal(begin(sentence), begin(sentence) + sentence.size() / 2, rbegin(sentence));
}