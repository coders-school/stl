#include "palindrome.hpp"
#include <algorithm>
#include <iostream>

bool is_palindrome(const std::string& word) {
    std::string firstPart;
    auto middle = begin(word);
    std::advance(middle, word.size()/2);
    std::copy(begin(word), middle, begin(firstPart));
    std::reverse(begin(firstPart), end(firstPart));
    std::cout << "firstPart: " << firstPart << '\n';
    std::string secondPart = word.substr(word.size() - word.size()/2, word.size());
    std::cout << "secondPart: " << secondPart << '\n';
    return firstPart == secondPart;
}
