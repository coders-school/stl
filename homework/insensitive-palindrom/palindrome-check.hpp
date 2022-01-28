#pragma once

#include <string>

// checks if the given text is a palindrome
// Is case insensitive, ignores special chars, like ,.?()[] and white spaces
bool is_palindrome(const std::string& text);

// returns string stripped of chars other than alphabethical
// and lowercased
std::string normalize(const std::string& text);