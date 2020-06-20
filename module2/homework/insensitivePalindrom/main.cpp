#include "checkPalindrome.hpp"
#include <iostream>

int main(){
    auto my_palindrome = is_palindrome("kaj..@@!#$@#$*ak1234    \nkaJaK");
    std::cout << my_palindrome << std::endl;
}           