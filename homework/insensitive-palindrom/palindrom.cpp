#include "palindrom.hpp"
#include <algorithm>
#include <string>
#include <cctype>

std::string sanitizeText(std::string text) {
    
    for_each(text.begin(), text.end(), [](char& character) { character = tolower(character); });
    text.erase(std::remove_if(text.begin(),
                              text.end(),
                              [](const char& character) {
                                  return !isalnum(character);
                              }),
               text.end());
    return text;
}

bool is_palindrome(const std::string& text) {
    std::string sanitizedText = sanitizeText(text);

    if (equal(sanitizedText.begin(), sanitizedText.begin() + sanitizedText.size() / 2, sanitizedText.rbegin())){
      return true;
    }
    else {
        return false;
    }
}

