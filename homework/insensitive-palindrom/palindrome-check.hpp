#pragma once

#include <string>

// checks if the given text is a palindrome
// Is case insensitive, ignores special chars, like ,.?()[] and white spaces
bool is_palindrome(const std::string& text);