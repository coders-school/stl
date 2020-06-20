#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string> wordsList) {
    wordsList.sort([](std::string a, std::string b) {
        if (a.size() == b.size()) {
            return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
        } else {
            return a.size() < b.size();
        }
    });
    std::deque<std::string> sortedWords(wordsList.begin(), wordsList.end());
    return sortedWords;
}
