#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string> list) {
    list.sort();
    std::deque<std::string> deq{list.begin(), list.end()};
    std::sort(deq.begin(), deq.end(), [](const std::string& first, const std::string& second) {
        return first.length() < second.length();
    });

    return deq;
}
