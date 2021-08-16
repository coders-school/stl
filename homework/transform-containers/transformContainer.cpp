#include "transformContainer.h"

#include "algorithm"

std::map<int,std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque) {
	list.sort();
	list.unique();
    deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

	std::map<int,std::string> result;
	auto createPair = [](const auto& str, const auto& val) { return std::make_pair(val, str); };
	std::transform(list.begin(), list.end(), deque.begin(), std::inserter(result, result.end()), createPair);
	return result;
}