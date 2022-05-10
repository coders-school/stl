#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& fList) {
    fList.sort([](const auto& lhs, const auto& rhs){
        return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() < rhs.size(); 
    });

    std::deque<std::string> deq{};
    for (auto& el : fList) {
        deq.emplace_back(el);
    }
    return deq;
}
