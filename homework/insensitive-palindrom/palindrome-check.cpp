#include "palindrome-check.hpp"

#include <algorithm>

// checks if the given text is a palindrome
// Is case insensitive, ignores special chars, like ,.?()[] and white spaces
bool is_palindrome(const std::string& text)
{
    // get a string ready for comparison
    // (containing only alpha chars and lower case)
    std::string normalized = normalize(text);

    // actual palindrome test
    return std::equal(begin(normalized),
                      begin(normalized) + normalized.size() / 2,
                      rbegin(normalized));
}

// returns string stripped of chars other than alphabethical
// and lowercased
std::string normalize(const std::string& text)
{
    std::string result;
    result.reserve(text.size());
    std::for_each(begin(text), end(text), [&result](auto ch) {
        if (isalpha(ch)) {
            result += tolower(ch);
        }
    });
    result.shrink_to_fit();

    return result;
}