#include "palindrome.hpp"

#include <algorithm>
#include <string>

void prepare_string(std::string& text) {
    auto delete_special_chars = [](char& c) {
        c = std::tolower(c);
        return !std::isalpha(c);
    };

    text.erase(std::remove_if(text.begin(), text.end(), delete_special_chars), text.end());
}

bool is_palindrome(std::string text) {
    prepare_string(text);
    return std::equal(text.begin(), std::next(text.begin(), text.size() / 2), text.rbegin());
}
