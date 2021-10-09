#pragma once
#include <algorithm>
#include <iostream>

bool is_palindrome(const std::string_view &str)
{
    using namespace std;
    std::string tmp;
    tmp.reserve(str.size());

    for_each(begin(str), end(str), [&tmp](auto x)
             {
                 if (x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z')
                 {
                     tmp.push_back(::tolower(x));
                 }
             });
    return std::equal(tmp.begin(), tmp.end(), tmp.rbegin());
}
