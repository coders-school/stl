#include "palindrome.hpp"
#include <iostream>

int main()
{

    std::string s;
    std::cout << "Specify string of charakter: ";
    std::getline(std::cin, s);

    if (is_palindrome(s)) {
        std::cout << "The given string is a palindrome. \n";
    } else {
        std::cout << "The given string isn't a palindrome. \n";
    }

    std::cout << std::endl;

    return 0;
}