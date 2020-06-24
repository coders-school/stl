#include "isPalindrome.hpp"

#include <algorithm>
#include <cctype>

bool is_palindrome(const std::string& text) {
    std::string pure_text;
    pure_text.reserve(text.size());
    std::for_each(text.begin(), text.end(),
                  [&pure_text](unsigned char letter) {
                      if (isalnum(letter)) {
                          pure_text += tolower(letter);
                      }
                  });
    pure_text.shrink_to_fit();

    return std::equal(pure_text.begin(), pure_text.begin() + (pure_text.size() / 2), pure_text.rbegin());
}
