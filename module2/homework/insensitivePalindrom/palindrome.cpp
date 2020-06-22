#include "palindrome.hpp"

#include <algorithm>

bool is_palindrome (const std::string& expression)
{
    std::string tmp;
    std::copy_if(expression.begin(), expression.end(),
            back_inserter(tmp), [](auto x) { return std::isalpha(x); });

    std::transform(tmp.begin(), tmp.end(), tmp.begin(), 
            [](unsigned c) { return std::tolower(c); });

    return std::equal(tmp.begin(), tmp.begin() + tmp.size()/2, tmp.rbegin());
}

