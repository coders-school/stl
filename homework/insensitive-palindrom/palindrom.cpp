#include <iostream>
#include "palindrom.hpp"

int main() {
     std::string my_str = "Are we not pure? “No, sir!” Panama’s moody Noriega brags."
                       "It is garbage!” Irony dooms a man—a prisoner up to new era.";
    std::cout << std::boolalpha << is_palindrome(my_str);
    return 0;
}
