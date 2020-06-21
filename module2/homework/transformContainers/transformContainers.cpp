#include "transformContainers.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& listOfWords, std::deque<int>& dequeOfNumbers) {
    std::map<int, std::string> transformedMap;

    listOfWords.sort();
    listOfWords.erase(std::unique(begin(listOfWords), end(listOfWords)), end(listOfWords));

    std::sort(dequeOfNumbers.begin(), dequeOfNumbers.end());
    dequeOfNumbers.erase(std::unique(begin(dequeOfNumbers), end(dequeOfNumbers)), end(dequeOfNumbers));

    std::transform(dequeOfNumbers.begin(), dequeOfNumbers.end(), listOfWords.begin(),
                   std::inserter(transformedMap, transformedMap.end()),
                   [](const int number, const std::string& word) {
                       return std::make_pair(number, word);
                   });

    return transformedMap;
}
