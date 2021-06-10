#include "sort.hpp"

bool sortAlpha(const std::string& lhs, const std::string& rhs) {
    if (lhs.size() == rhs.size()) {
        return lhs < rhs;
    } 
    return lhs.size() < rhs.size();
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& fList) {
    std::deque<std::string> deq {};
    fList.sort(sortAlpha);
    for (const auto& el : fList) {
        deq.push_back(el);
    }
    return deq;
}