#include "transformContainers.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deque) {
    list.sort();
    list.unique();

    std::sort(deque.begin(), deque.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

    if (deque.size() != list.size()) {
        return std::map<int, std::string>{};
    }

    std::map<int, std::string> map{};

    std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(map, map.end()),
                   [](int lhs, std::string& rhs) {
                       return std::pair<int, std::string>(lhs, rhs);
                   });
    return map;
}
