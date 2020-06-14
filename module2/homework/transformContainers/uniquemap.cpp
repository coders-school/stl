#include "uniquemap.hpp"

#include <algorithm>
#include <iterator>
#include <utility>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& inputList,
                                                           std::deque<int>& inputDeque) {

    inputList.sort();
    inputList.erase(std::unique(inputList.begin(), inputList.end()), inputList.end());

    std::sort(inputDeque.begin(), inputDeque.end());
    inputDeque.erase(std::unique(inputDeque.begin(), inputDeque.end()), inputDeque.end());

    std::map<int, std::string> outputMap;
    std::transform(inputDeque.begin(), 
                   inputDeque.end(),
                   inputList.begin(),
                   std::inserter(outputMap, outputMap.end()),
                   [](const auto& deqElement, const auto& lisElement) {
    return std::make_pair(deqElement, lisElement);
    });

return outputMap;
}
