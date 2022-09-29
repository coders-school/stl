#include <algorithm>
#include <utility>

#include "sort.hpp"

void sortByLength(std::deque<std::string>& deque, std::forward_list<std::string>& fList, unsigned int size) {
    std::vector<std::pair<unsigned int, unsigned int>> sizeVector;
    sizeVector.reserve(size);
    unsigned int order = 0;
    for (const std::string& el : fList) {
        sizeVector.emplace_back(std::pair(el.length(), order++));
    }
    std::sort(sizeVector.begin(), sizeVector.end());
    order = 0;
    for (const std::string& el : fList) {
        int index = 0;
        while (order != sizeVector[index].second) {
            index++;
        }
        deque[index] = el;
        ++order;
    }
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& fList) {
    std::deque<std::string> deque;
    unsigned int listSize = std::distance(fList.cbegin(), fList.cend());
    deque.resize(listSize);
    fList.sort();
    sortByLength(deque, fList, listSize);

    return deque;
}
