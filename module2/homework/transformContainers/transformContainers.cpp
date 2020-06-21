#include "transformContainers.h"

std::map<int, std::string>& removeDuplicateAndTranformToMap(std::list<std::string> texts, std::deque<int> numbers)
{
	std::sort(numbers.begin(), numbers.end());
	deque.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());

	texts.sort();
	texts.erase(std::unique(texts.begin(), texts.end()), texts.end());

	std::map<int, std::string> mapToReturn;
	std::transform(numbers.begin(), numbers.end(), texts.begin(), std::inserter(mapToReturn, mapToReturn.end()), [](int text, std::string number) {return std::pair(text, number); });

	return mapToReturn;
}

