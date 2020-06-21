#include "palindrome.hpp"

#include <algorithm>

bool is_palindrome(const std::string& PalStr) {
    std::string PalCopy = PalStr;

    PalCopy.erase(std::remove_if(begin(PalCopy), end(PalCopy), [](const auto& sign) { return !(std::isalpha(sign)); }), end(PalCopy));
    std::transform(begin(PalCopy), end(PalCopy), begin(PalCopy), [](auto& sign) { return std::tolower(sign); });
    return std::equal(begin(PalCopy), begin(PalCopy) + PalCopy.size() / 2, rbegin(PalCopy));
}
