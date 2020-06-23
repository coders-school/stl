#include <algorithm>
#include <cctype>
#include <string>

bool is_palindrome(std::string text)
{
    text.erase(std::remove_if(text.begin(), text.end(), [](unsigned char x) { return !std::isalpha(x); }), text.end());
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) { return std::tolower(c); });
    std::string text_cp = text;
    reverse(text_cp.begin(), text_cp.end());
    return text == text_cp;
}
