#include <iostream>
#include "palindrome.hpp"

void testText(std::string str){
    
    std::cout << "\"" << str << "\" "
        << (is_palindrome(str) ? "is" : "is not")
        << " a palindrome\n";
}

int main() {
    testText("Eva, can I see bees in a cave?");
    testText("ala");
    testText("All lets Della call Ed “Stella.”");   

    return 0;
}