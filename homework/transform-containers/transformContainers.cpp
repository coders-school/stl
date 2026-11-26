
#include "transformContainers.hpp"

#include <algorithm>
#include <iterator>
#include <set>
#include <utility>

std::map<int, std::string> removeDuplicateAndTranformToMap(
    const std::list<std::string>& strings,
    const std::deque<int>& numbers) {
    std::set<std::string> uniqueStrings(
        strings.begin(), strings.end());

    std::set<int> uniqueNumbers(
        numbers.begin(), numbers.end());

    std::map<int, std::string> result;

    std::transform(
        uniqueNumbers.begin(),
        uniqueNumbers.end(),
        uniqueStrings.begin(),
        std::inserter(result, result.begin()),
        [](int number, const std::string& text) {
            return std::make_pair(number, text);
        });

    return result;
}
