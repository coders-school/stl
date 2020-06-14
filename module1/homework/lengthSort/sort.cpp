#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& fList) {
    
    fList.sort([](const std::string& lhs, const std::string& rhs) {
        return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
    });

    std::deque<std::string> result(fList.begin(), fList.end());

    return result;
}
