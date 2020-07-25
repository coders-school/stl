#include <forward_list>
#include <iostream>
#include <string>

#include "sort.hpp"


template <typename Container>
void printCollection(const Container& collection) {
    for (const auto& element : collection) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::forward_list<std::string> words = {"Somebody", "once",  "told", "me",
                                              "the",      "world", "is",   "gonna",
                                              "roll",     "me"};

    printCollection(words);
    auto sorted = lengthSort(words);
    printCollection(sorted);

    return 0;
}
