#include <algorithm>
#include <utility>

#include "transformContainers.hpp"


std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list,  std::deque<int> deque) {
	

	std::map<int, std::string> createdMap{};

	list.sort();
	list.erase(std::unique(list.begin(), list.end()),
                   list.end());

	std::sort(deque.begin(), deque.end());
	deque.erase(std::unique(deque.begin(), deque.end()),
                   deque.end());


	std::transform(deque.begin(), 
		       deque.end(),
		       list.begin(),
		       std::inserter(createdMap, createdMap.end()), 
		       [](const auto& num, const auto& str){ 
				return std::make_pair(num, str);										
		       } );

	return createdMap;
}

