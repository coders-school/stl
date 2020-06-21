#include "ispalindrome.hpp"

#include <algorithm>

bool is_palindrome (std::string expression)
{
    expression.erase(std::remove_if(expression.begin(), expression.end(), 
            [](unsigned x) { return std::isspace(x) || std::ispunct(x); }), expression.end());

    std::transform(expression.begin(), expression.end(), expression.begin(), 
            [](unsigned c) { return std::tolower(c); });

    return std::equal(expression.begin(), expression.begin() + expression.size()/2, expression.rbegin());
}

