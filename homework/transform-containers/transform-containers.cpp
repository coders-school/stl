#include "transform-containers.hpp"
#include <iterator>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deque) {
    std::map<int, std::string> result;
    // Removing duplicates from list
    list.sort();
    auto p = std::unique(list.begin(), list.end());
    list.erase(p, list.end());

    // Removing duplicates from deque
    std::sort(deque.begin(), deque.end());
    auto pd = std::unique(deque.begin(), deque.end());
    deque.erase(pd, deque.end());

    // Transforming two containers to the output container
    std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(result, result.end()), [](auto first, auto seond) { return std::make_pair(first, seond); });

    return result;
}
