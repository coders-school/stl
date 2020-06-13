#include "sort.hpp"

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list) {

    std::deque<std::string> deq{};
    auto listIt = list.begin();

    if (!list.empty()) {
        deq.insert(deq.begin(), *listIt);
        listIt++;
    }

    for (; listIt != list.end(); listIt++) {
        auto deqIt = deq.begin();
        for (; deqIt != deq.end(); deqIt++) {
            if ((*listIt).length() < (*deqIt).length()) {
                deq.insert(deqIt, *listIt);
                break;
            } else if ((*listIt).length() == (*deqIt).length()) {
                if (*listIt < *deqIt) {
                    deq.insert(deqIt, *listIt);
                    break;
                }
            }
        }
        if (deqIt == deq.end()) {
            deq.insert(deqIt, *listIt);
        }
    }

    return deq;
}