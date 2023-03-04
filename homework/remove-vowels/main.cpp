#include <iostream>
#include <string>
#include <vector>
#include "vowel.hpp"



template <typename T>
void printVector(const std::vector<T>& collection) {

    for (const auto& element : collection) {
        std::cout << element << '\n';
    }
    std::cout << '\n';
}


int main() {
    std::vector<std::string> words = {
        "Somebody once told me the world is gonna rolla me",
        "I ain't the sharpest tool in the shed",
        "She was looking kind of dumb with her finger and her thumb",
        "In the shape of an L on her forehead"};
    printVector(words);
    removeVowels(words);
    std::cout << "\n---------------------------------------------------------------------------\n";
    printVector(words);

    return 0;
}
