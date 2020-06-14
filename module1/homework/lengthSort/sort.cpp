#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    list.sort();
    std::deque<std::string> deq{list.begin(), list.end()};
    std::string tempStr;
    auto swap = [&tempStr](auto first, auto second) {
        tempStr = first;
        first = second;
        second = tempStr;
    };

    for (auto element : deq) {
        for (int i = 0; i < (deq.size() - 1); i++) {
            if (deq[i].size() > deq[i + 1].size())
                swap(deq[i], deq[i + 1]);
        }
    }
    return deq;
}
