#include "detector.hpp"
#include <algorithm>


int main(){
    std::string word;
    std::cout << "Type a word: ";
    std::cin >> word;
    std::cout << word << is_palindrome(word);
    return 0;
}