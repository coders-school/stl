#include <iostream>
#include <string>
#include "checkPalindrome.hpp"


int main() {
    std::string my_str = "All lets Della call Ed “Stella.”";
    std::cout << std::boolalpha << is_palindrome(my_str) << '\n';

}
