#include "sort.hpp"

bool myCompare(const std::string& a, const std::string& b) {
    return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

bool setOrder(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

std::deque<std::string> setDeque(const std::forward_list<std::string>& list) {
    std::deque<std::string> newDeque;
    for (const auto& element : list) {
        newDeque.push_back(element);
    }
    return newDeque;
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    list.sort(myCompare);
    list.sort(setOrder);
    auto newDeque = setDeque(list);
    return newDeque;
}
