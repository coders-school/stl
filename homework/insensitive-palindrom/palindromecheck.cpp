#include "palindromecheck.hpp"

bool is_palindrome(std::string Text)
{
    std::transform(Text.begin(), Text.end(), Text.begin(), [](auto character)

                   { return std::toupper(character); });
    Text.erase(std::remove_if(Text.begin(), Text.end(), [](auto character)
                              { return character < 'A' || character > 'Z'; }),
               Text.end());

    std::string ReversedText;
    ReversedText.resize(Text.size());
    std::reverse_copy(Text.begin(), Text.end(), ReversedText.begin());
    return Text == ReversedText;
}
