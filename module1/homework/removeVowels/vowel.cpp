#include "vowel.hpp"
#include <algorithm>


void filterString(std::string &str, const std::string &filter) {

    auto filterLetter = [&filter](const auto letter) {
        return std::any_of(begin(filter), end(filter),
                           [letter](auto vowel) { return vowel == std::tolower(letter); });
    };

    for (const auto &letter : str)
        str.erase(std::remove_if(begin(str), end(str), filterLetter),
                  end(str));
}

void removeVowels(std::vector<std::string> &vec) {
    std::for_each(begin(vec), end(vec),
                  [](auto &s) { filterString(s, vowels); });
}
