#include "transform_containers.hpp"
#include <algorithm>

 std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& strings,
                                std::deque<int>& numbers) {

    strings.sort();
    std::sort(numbers.begin(), numbers.end());

    strings.erase(std::unique(strings.begin(), strings.end()), strings.end());
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());

    std::map<int, std::string> uniqueMap;

    std::transform(numbers.begin(), numbers.end(),
            begin(strings),
            inserter(uniqueMap, uniqueMap.end()),
            [](const auto& number, const auto& string) {
                return make_pair(number, string);
            });

    return uniqueMap;
}