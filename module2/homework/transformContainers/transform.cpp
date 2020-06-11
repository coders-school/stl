#include "transform.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deq) {
    list.sort();
    list.erase(std::unique(list.begin(), list.end()), list.end());

    std::sort(deq.begin(), deq.end());
    deq.erase(std::unique(deq.begin(), deq.end()), deq.end());

    std::map<int, std::string> map;
    std::transform(deq.begin(), deq.end(), list.begin(), deq.begin(), [&map](const auto& first, const auto& second){
            map[first] = second;
            return first;
    });

    return map;
}
