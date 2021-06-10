#include "sort.hpp"
#include <algorithm>
#include <deque>
#include <forward_list>
#include <string>

bool compareLength(std::string word, std::string next_word) {
    if (word.length() < next_word.length())
        return true;
    if ((word.length() == next_word.length()) && (word < next_word))
        return true;
}
std::deque<std::string> lengthSort(std::forward_list<std::string> container_forward_list) {
    container_forward_list.sort(compareLength);
    std::deque<std::string> container_deque(container_forward_list.begin(), container_forward_list.end());
    return container_deque;
}