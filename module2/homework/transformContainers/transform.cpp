#include "transform.hpp"
#include <algorithm>
#include <iterator>

std::map<int, std::string> removeDuplicateAndTransformToMap(std::list<std::string> aList,
                                                            std::deque<int> aDeque) {
    std::map<int, std::string> result;

    aList.sort();
    std::sort(aDeque.begin(), aDeque.end());

    aDeque.erase(std::unique(aDeque.begin(), aDeque.end()), aDeque.end());
    aList.erase(std::unique(aList.begin(), aList.end()), aList.end());

    std::transform(aList.cbegin(), aList.cend(), aDeque.cbegin(),
                   std::inserter(result, result.end()),
                   [](const std::string& aString, int aNum) {
                       return std::make_pair(aNum, aString);
                   });
    return result;
}
