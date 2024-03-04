#include "mergeConteiners.hpp"

    std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deque) {
    std::map<int, std::string> mergeContiners;
    list.sort();
    list.unique();  
    std::sort(deque.begin(), deque.end());
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());
    std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(mergeContiners, mergeContiners.end()),
                    [](const auto& a, const auto& b) { return std::make_pair(a, b); });
    return mergeContiners;
}
