#include "sort.hpp"
#include <deque>
#include <forward_list>
#include <string>

std::deque<std::string> lengthSort(std::forward_list<std::string> list) {
    std::deque<std::string> dq{};
    list.sort([](std::string lhs, std::string rhs) {
        if (lhs.size() == rhs.size()) {
            return lhs < rhs;  //lexicographic comparison if size are equal
        } else {
            return lhs.size() < rhs.size();  //sort by string size
        }
    });
    for (auto& x : list) {
        dq.push_back(x);
    }
    return dq;
}