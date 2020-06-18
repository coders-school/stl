#include <algorithm>

#include "tranform.hpp"

std::map<int, std::string> transformContainers(
    std::list<std::string> uniqueList,
    std::deque<int> uniqueDeque) {
    uniqueList.sort();
    uniqueList.erase(std::unique(uniqueList.begin(), uniqueList.end()), uniqueList.end());

    std::sort(uniqueDeque.begin(), uniqueDeque.end());
    uniqueDeque.erase(std::unique(uniqueDeque.begin(), uniqueDeque.end()), uniqueDeque.end());
}
