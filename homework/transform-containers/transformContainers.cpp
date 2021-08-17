#include "transformContainers.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> listOfStrings, std::deque<int> dequeOfInts) {
    listOfStrings.sort();
    listOfStrings.unique();

    std::sort(dequeOfInts.begin(), dequeOfInts.end());
    auto last = std::unique(dequeOfInts.begin(), dequeOfInts.end());
    dequeOfInts.erase(last, dequeOfInts.end());

    auto pair = [](const int & d, std::string l) { return std::make_pair(d, l); };

    std::map<int, std::string> bigMap;
    std::transform(dequeOfInts.begin(), dequeOfInts.end(), listOfStrings.begin(), std::inserter(bigMap, bigMap.end()), pair);

    return bigMap;
}
