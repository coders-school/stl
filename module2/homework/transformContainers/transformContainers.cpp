#include "transformContainers.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> stringList, std::deque<int> intDeque) {
std::map<int, std::string> result;

stringList.sort();
std::sort(intDeque.begin(), intDeque.end());

intDeque.erase(std::unique(intDeque.begin(), intDeque.end()), intDeque.end());
stringList.erase(std::unique(stringList.begin(), stringList.end()), stringList.end());

std::transform(intDeque.begin(), intDeque.end(), stringList.begin(), std::inserter(result, result.end()), [](const int& key, const std::string& value) { return std::make_pair(key, value); });

return result;
}
