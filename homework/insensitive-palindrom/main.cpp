#include<iostream>
#include"palindrom.hpp"

int main(int argc, char const *argv[])
{
    auto a = is_palindrome("abcd?");
    auto b = is_palindrome("ab a");
    auto c = is_palindrome("abba?");
    auto d = is_palindrome("Eva, can I see bees in a cave?");
    return 0;
}
