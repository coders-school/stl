#include "header.hpp"

bool is_palindrome(std::string txt)
{
    std::for_each(txt.begin(), txt.end(), [](auto& el) {el = tolower(el); });
    std::for_each(txt.begin(), txt.end(), [](auto& el) {if (!isalpha(el)) el = ' '; });

    txt.erase(std::remove(txt.begin(), txt.end(), ' '), txt.end());

    std::string rev_txt;
    rev_txt.resize(txt.size());

    std::reverse_copy(txt.begin(), txt.end(), rev_txt.begin());

    return(txt == rev_txt ? true : false);
}

