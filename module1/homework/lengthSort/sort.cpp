#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& fList) {
    std::deque<std::string> deq;
    
    fList.sort([](const std::string& lhs, const std::string& rhs) {
        return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
    });

    for (const auto& el : fList) {
        deq.push_back(el);
    }

    return deq;
}