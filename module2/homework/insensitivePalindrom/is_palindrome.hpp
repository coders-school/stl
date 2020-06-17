#include <string>
bool is_palindrome(const std::string & text)
{
    std::string text_cp = text;
    reverse(text_cp.begin(), text_cp.end());
    return text == text_cp;
}


