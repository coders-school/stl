#include "transform.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
    std::sort(deque.begin(), deque.end());
    std::unique(deque.begin(), deque.end());

    list.sort();
    auto lastElem = std::unique(list.begin(), list.end());
    list.erase(lastElem, list.end());

    std::map<int, std::string> map;

    try {
        auto zip = [](const int i, const std::string& s) { return std::make_pair(i, s); };
        std::transform(deque.begin(), deque.end(), list.begin(), std::inserter(map, map.end()), zip);
    } catch (const std::bad_alloc& e) {
        std::cout << "Allocation failed: " << e.what() << '\n';
    }

    return map;
}