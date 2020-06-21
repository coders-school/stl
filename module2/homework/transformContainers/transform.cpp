#include "transform.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& words, std::deque<int>& numbers) {
    std::map<int, std::string> resultMap;

    words.sort();
    words.unique();

    std::sort(numbers.begin(), numbers.end());
    auto last = std::unique(numbers.begin(), numbers.end());
    numbers.erase(last, numbers.end());

    std::transform(words.begin(), words.end(), numbers.begin(), std::inserter(resultMap, resultMap.end()),
                   [](const auto& str, const auto num) {
                       return std::make_pair(num, str);
                   });

    return resultMap;
}

