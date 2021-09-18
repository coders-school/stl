#include <iostream>
#include "palindrome.hpp"

int main() {
    // std::cout << "Enter word to check: ";
    // std::string word = "{}a 2bbbIUFYTCa618734eywr9pywe(*&%(&^$*%#(";
    // std::string word = "Eva, can I see bees in a cave?";
    std::string word = "Are we not pure? “No, sir!” Panama’s moody Noriega brags."
                       "It is garbage!” Irony dooms a man—a prisoner up to new era.";
    std::cout << "Word: " << word << '\n';
    // std::cin >> word;
    word = clean_word(word);
    std::cout << "Cleaned word: " << word << '\n';
    std::cout << "Is palindrome?\n" << std::boolalpha << is_palindrome(word) << '\n';
}
