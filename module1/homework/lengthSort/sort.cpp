#include "sort.hpp"

#include <algorithm>

bool compareWords(std::string first, std::string second) {
    return first.length() == second.length() ? first < second : first.length() < second.length();
}

std::deque<std::string> lengthSort(const std::forward_list<std::string>& words) {
    std::deque<std::string> sortedWords;
    sortedWords.insert(sortedWords.begin(), words.begin(), words.end());
    std::sort(sortedWords.begin(), sortedWords.end(), compareWords);

    return sortedWords;
}
