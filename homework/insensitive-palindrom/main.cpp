#include "palindrome.hpp"
#include <iostream>

int main()
{
    std::string s = "Are we not pure? “No, sir!” Panama’s moody Noriega brags."
                       "It is garbage!” Irony dooms a man—a prisoner up to new era.";
    //std::cout << "Specify string of character: ";
    //std::getline(std::cin, s);

    if (is_palindrome(s)) {
        std::cout << "The given string is a palindrome. \n";
    } else {
        std::cout << "The given string isn't a palindrome. \n";
    }
    std::cout << std::endl;

    return 0;
}