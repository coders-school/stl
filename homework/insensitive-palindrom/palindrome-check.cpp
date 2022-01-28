#include "palindrome-check.hpp"

#include <algorithm>
#include <iostream>   // REMOVE

// checks if the given text is a palindrome
// Is case insensitive, ignores special chars, like ,.?()[] and white spaces
bool is_palindrome(const std::string& text)
{
    // get a string ready for comparison
    // (select only alpha chars and make them lower case)
    std::string normalized = normalize(text);
    std::cout << "text:\t" << text << 'n'
              << "alpha only: " << normalized
              << "\n---------------------\n";
    return false;
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