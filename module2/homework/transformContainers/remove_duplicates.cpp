#include "remove_duplicates.hpp"

#include <algorithm>
#include <numeric>
#include <set>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> values, std::deque<int> keys) {
    std::map<int, std::string> joinedUniqeCollections;

    values.sort();
    std::unique(values.begin(), values.end());

    std::set<int> uniqueKeys;
    std::copy(keys.begin(), keys.end(), std::inserter(uniqueKeys, uniqueKeys.end()));

    int lowerSize = std::min(uniqueKeys.size(), values.size());

    std::transform(uniqueKeys.begin(), std::next(uniqueKeys.begin(), lowerSize),
                   values.begin(), std::inserter(joinedUniqeCollections, joinedUniqeCollections.end()),
                   [](auto key, auto value) { return std::make_pair(key, value); });
    return joinedUniqeCollections;
}
