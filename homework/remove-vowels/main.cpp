#include <iostream>
#include <string>
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
        "Somebody once told me the world is gonna roll me",
        "I ain't the sharpest tool in the shed",
        "She was looking kind of dumb with her finger and her thumb",
        "In the shape of an L on her forehead"
    };
    printVector(words);
    removeVowels(words);
     for (auto elem : removeVowels(words)){
        std::cout << elem << '\n';
    }

    return 0;
}
