#include "sort.hpp"
#include <iostream>
#include <string>

bool wordsSort(std::string s1, std::string s2);

std::deque<std::string> lengthSort(std::forward_list<std::string> fli) {
    std::deque<std::string> deq;
    fli.sort();
    fli.sort(wordsSort);

    for (auto it = fli.begin(); it != fli.end(); ++it) {
        std::cout << (*it).size() << " ";

        deq.emplace_back(*it);
    }
    std::cout << " \n";
    return deq;
}

bool wordsSort(std::string s1, std::string s2) {
    return (s1.length() < s2.length());
}