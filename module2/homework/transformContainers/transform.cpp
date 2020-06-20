#include "transform.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
    list.sort();
    list.erase(std::unique(list.begin(), list.end()), list.end());

    std::sort(deque.begin(), deque.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

    std::map<int, std::string> result;
    std::transform(
        deque.begin(), deque.end(), list.begin(), deque.begin(), [&result](auto first, auto second) {
            result[first] = second;
            return first;
        });

    return result;
}