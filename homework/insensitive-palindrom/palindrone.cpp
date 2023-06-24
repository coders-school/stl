#include "palindrone.h"

bool is_palindrome(std::string s) {
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
                return !std::isalnum(c);
            }),
            s.end());

    std::transform(s.begin(), s.end(), s.begin(), [](char c) { return std::tolower(c); });
    return std::equal(s.begin(), s.end(), s.rbegin(), s.rend());
}
