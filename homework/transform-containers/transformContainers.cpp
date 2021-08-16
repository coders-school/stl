#include "transformContainers.hpp"

#include <algorithm>
#include <iterator>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deque) {
    std::map<int, std::string>map;
    list.sort();
    std::sort(begin(deque), end(deque));
    list.erase(std::unique(begin(list), end(list)), end(list));
    deque.erase(std::unique(begin(deque), end(deque)), end(deque));
    if (deque.size() == list.size()) {
        std::transform(begin(deque), end(deque), begin(list), std::inserter(map, map.end()), [](auto a, auto b){return std::make_pair(a, b);});
    }
    return map;
}
