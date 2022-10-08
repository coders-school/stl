#include "insensitivePalindrom.hpp"

#include <algorithm>

bool is_palindrome(const std::string& word) {
    std::string wordAlphabetic;
    std::copy_if(word.cbegin(), word.cend(), std::back_inserter(wordAlphabetic), [](char c) {
        return isalpha(c);
    });
    std::transform(wordAlphabetic.begin(), wordAlphabetic.end(), wordAlphabetic.begin(), [](char c) {
        return tolower(c);
    });
    auto itMiddle = std::next(wordAlphabetic.cbegin(), (wordAlphabetic.size() + 1) / 2);
    auto revMiddle = std::make_reverse_iterator(std::next(wordAlphabetic.cbegin(), wordAlphabetic.size() / 2));
    auto it = std::search(wordAlphabetic.cbegin(), itMiddle, wordAlphabetic.crbegin(), revMiddle);

    return it != itMiddle;
}
