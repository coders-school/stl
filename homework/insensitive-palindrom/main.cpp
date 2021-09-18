#include <iostream>
#include "palindrome.hpp"

int main() {
    std::string string =
        "Are we not pure? “No, sir!” Panama’s moody Noriega brags."
        "It is garbage!” Irony dooms a man—a prisoner up to new era.";
    std::cout << "String: " << string << '\n';
    string = clean_string(string);
    std::cout << "Cleaned string: " << string << '\n';
    std::cout << "Is the string palindrome? " << std::boolalpha << is_palindrome(string) << '\n';
}
