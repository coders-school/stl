#include "palindrome.hpp"

bool is_palindrome(const std::string& input) {
    std::string modified{};
    std::copy_if(input.begin(), input.end(), std::back_inserter(modified), ::isalnum);
    std::transform(modified.begin(), modified.end(), modified.begin(), ::tolower);
    return std::equal(modified.begin(), modified.begin() + modified.size()/2, modified.rbegin());
}
