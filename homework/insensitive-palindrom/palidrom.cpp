#include "palidrom.hpp"
#include <algorithm>

bool is_palindrome(const std::string& text) {
    std::string filtered;
    std::copy_if(begin(text), end(text), std::back_inserter(filtered),
                 [](auto letter) {
                     return isalnum(letter);
                 });

    std::string::const_iterator half = filtered.cbegin();
    std::advance(half, (std::distance(filtered.cbegin(), filtered.cend())) / 2);

    auto pair = std::mismatch(
        filtered.cbegin(),
        half,
        filtered.crbegin(),
        [](const auto& letter1, const auto& letter2) {
            return tolower(letter1) == tolower(letter2);
        });

    if (pair.first != half) {
        return false;
    }
    return true;
}
