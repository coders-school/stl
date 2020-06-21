#include "sort.hpp"

#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    struct Greater {
        bool operator()(const std::string& first, const std::string& second) {
            if (first.size() == second.size()) {
                return first <= second;
            }

            return first.size() <= second.size();
        }
    };

    list.sort(Greater());
    std::deque<std::string> deq{list.begin(), list.end()};

    return deq;
}
