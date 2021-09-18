#include "palindrome.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>

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

std::string clean_word(const std::string& word) {
    std::string cleanedWord;
    std::copy_if(begin(word),
                 end(word),
                 std::back_inserter(cleanedWord),
                 [](auto sign) {
                     return 96 < sign && sign < 123;
                 });
    return cleanedWord;
}

