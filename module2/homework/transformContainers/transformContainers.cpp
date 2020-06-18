#include "transformContainers.hpp"

#include <algorithm>
#include <iostream>

std::map<int, std::string> removeDuplicateAndTranformToMap(
    std::list<std::string>& str,
    std::deque<int>& numbers) {
    str.sort();
    std::sort(numbers.begin(), numbers.end());

    str.erase(std::unique(str.begin(), str.end()), str.end());
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());

    std::map<int, std::string> map;
    if (str.size() != numbers.size()) {
        std::cerr << "List size is not equal to deque size!\n";
        return map;
    }

    std::transform(numbers.begin(), numbers.end(), str.begin(), std::inserter(map, map.end()),
    [](const int& num, const std::string& str) { return std::make_pair(num, str); });

    return map;
}
