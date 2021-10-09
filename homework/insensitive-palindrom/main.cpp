#include "Palindrome.hpp"
#include <iostream>
int main()
{
    auto x1 = "abab";
    auto x2 = "abba";
    std::cout << is_palindrome(x1);
    std::cout << '\n';
    std::cout << is_palindrome(x2);
    return 0;
}
