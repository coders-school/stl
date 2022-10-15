#include "sort.hpp"

void bubbleSortSwap(std::string* lhs, std::string* rhs) {
    if (!rhs->empty()) {
        if (lhs->length() > rhs->length()) {
            auto temp = *lhs;
            *lhs = *rhs;
            *rhs = temp;
        }
    }
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    list.sort();  // Initial alphabetical sort
    std::deque<std::string> sortedList{};

    for (auto& element : list) {
        sortedList.push_back(element);  // Push all elements to the deque
    }

    for (auto word : sortedList) {  // Perform sort operation for all element in list
        for (auto& element : sortedList) {
            bubbleSortSwap(&element, &element + 1);
        }
    }

    return sortedList;
}
