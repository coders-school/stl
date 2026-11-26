#include "palindrome.hpp"

#include <algorithm>
#include <cctype>
#include <iterator>

bool is_palindrome(const std::string& text) {
    std::string cleaned;

    std::copy_if(
        text.begin(),
        text.end(),
        std::back_inserter(cleaned),
        [](unsigned char c) {
            return std::isalnum(c);
        });

    std::transform(
        cleaned.begin(),
        cleaned.end(),
        cleaned.begin(),
        [](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        });

    return std::equal(
        cleaned.begin(),
        cleaned.end(),
        cleaned.rbegin());
}
