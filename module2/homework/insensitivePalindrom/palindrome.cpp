#include "palindrome.hpp"

#include <algorithm>

bool is_palindrome(std::string word) {
    std::transform(word.begin(),
                   word.end(),
                   word.begin(),
                   [](char ch) { return std::tolower(ch); });

    word.erase(std::remove_if(word.begin(),
                              word.end(),
                              [](char ch) {
                                  return !std::isalpha(ch);
                              }),
               word.end());

    return std::equal(word.begin(), word.begin() + word.size() / 2, word.rbegin());
}
