#include "transformContainers.hpp"
#include <algorithm>
#include <iostream>

void removeDuplicates(std::list<std::string>& list) {
    list.sort();
    list.erase(std::unique(list.begin(), list.end()), list.end());
}

void removeDuplicates(std::deque<int>& deque) {
    std::sort(deque.begin(), deque.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());
}

std::map<int, std::string> tranformToMap(std::deque<int>& deque, std::list<std::string>& list) {
    std::map<int, std::string> map;
    if (deque.size() != list.size()) {
        std::cout << "Containers must be of the same size";
    } else {
        std::transform(begin(deque), end(deque), begin(list), std::inserter(map, end(map)),
                       [](auto key, auto value) { return std::make_pair(key, value); });
    }
    return map;
}

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deque) {
    removeDuplicates(list);
    removeDuplicates(deque);
    auto map = tranformToMap(deque,list);
    return map;
}
