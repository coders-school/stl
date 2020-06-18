#include "remove_duplicates.hpp"

#include <algorithm>
#include <numeric>
#include <set>

std::map<int, std::string> removeDuplicateAndTranformToMap(const std::list<std::string>& values, const std::deque<int>& keys) {
    std::map<int, std::string> joinedUniqeCollections;

    std::list<std::string> uniqueValues(values.begin(), values.end());

    uniqueValues.sort();
    std::unique(uniqueValues.begin(), uniqueValues.end());

    std::set<int> uniqueKeys;
    std::copy(keys.begin(), keys.end(), std::inserter(uniqueKeys, uniqueKeys.end()));

    int lowerSize = std::min(uniqueKeys.size(), uniqueValues.size());

    std::transform(uniqueKeys.begin(), std::next(uniqueKeys.begin(), lowerSize), uniqueValues.begin(), std::inserter(joinedUniqeCollections, joinedUniqeCollections.end()), [](auto key, auto value) { return std::make_pair(key, value); });
    return joinedUniqeCollections;
}
