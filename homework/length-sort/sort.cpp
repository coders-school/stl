#include "sort.hpp"

std::deque<std::string> lengthSort(const std::forward_list<std::string> fl) {
    std::deque<std::string> deq;

    for (const auto& el : fl) {
        deq.push_back(el);
    }

    std::sort(deq.begin(), deq.end());

    for (int i = 0; i < deq.size(); i++) {
        for (int j = 0; j < deq.size() - 1; j++) {
            if (deq[j].length() > deq[j + 1].length()) {
                std::swap(deq[j], deq[j + 1]);
            }
        }
    }

    return deq;
}