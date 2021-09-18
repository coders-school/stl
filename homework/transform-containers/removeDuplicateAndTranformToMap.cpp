#include "removeDuplicateAndTranformToMap.hpp"
#include <algorithm>
#include <iostream>
#include <utility>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
    std::map<int, std::string> map;
    list.sort();
    list.unique();
    std::sort(begin(deque), end(deque));
    auto dequeEnd = std::unique(begin(deque), end(deque));
    deque.erase(dequeEnd, end(deque));
    std::transform(begin(list),
                   end(list),
                   begin(deque),
                   std::inserter(map, end(map)),
                   [](auto listElement, auto dequeElement) {
                       return std::make_pair(dequeElement, listElement);
                   });
    return map;
}
