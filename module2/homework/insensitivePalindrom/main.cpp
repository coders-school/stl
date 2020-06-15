#include <iostream>
#include <string>
#include "palindrome.hpp"

int main() {
    std::string str =
        "Are we not pure? “No, sir!” Panama’s moody Noriega brags."
        "It is garbage!” Irony dooms a man—a prisoner up to new era.";
    if (is_palindrome(str)) {
        std::cout << "Its insensitive palindrome\n";
    } else {
        std::cout << "Its not insensitive palindrome\n";
    }
    return 0;
}
