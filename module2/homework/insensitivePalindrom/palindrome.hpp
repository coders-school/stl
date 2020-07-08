#pragma once

#include <algorithm>
#include <cctype>

bool is_palindrome(const std::string &text)
{
    std::string temp = text;

    temp.erase(std::remove_if(begin(temp), end(temp), [](char c){ return !std::isalpha(c); }), end(temp));
    std::transform(begin(temp), end(temp), begin(temp), [](unsigned char c) {
        return std::tolower(c); });

    return std::equal(begin(temp), begin(temp) + temp.size() / 2, rbegin(temp));
}
