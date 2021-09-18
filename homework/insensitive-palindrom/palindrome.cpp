#include "palindrome.hpp"
#include <algorithm>
#include <iostream>

bool is_palindrome(const std::string& word) {
    int length = word.size();
    int middle = length / 2;
    std::string firstPart = word.substr(0, middle);
    std::cout << "firstPart: " << firstPart << '\n';
    std::string secondPart = word.substr(length - middle, length);
    std::reverse(begin(secondPart), end(secondPart));
    std::cout << "secondPart: " << secondPart << '\n';
    return firstPart == secondPart;
}
