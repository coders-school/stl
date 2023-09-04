#include "palindrome.hpp"

bool is_palindrome(std::string t1) {
    auto itr = std::remove_if(std::begin(t1), std::end(t1), [](const char c) { return !(std::islower(c) || std::isupper(c)); });
    t1.erase(itr, t1.end());
    std::transform(t1.begin(), t1.end(), t1.begin(), [](const char c) { return std::tolower(c); });
    return std::equal(t1.begin(), t1.end(), t1.rbegin(), t1.rend());
}
