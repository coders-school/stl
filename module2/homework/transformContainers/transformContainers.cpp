#include "transformContainers.hpp"
#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> listWords, std::deque<int> dequeNumbers){
    listWords.sort();
    std::sort(dequeNumbers.begin(), dequeNumbers.end());
    listWords.erase(std::unique(listWords.begin(), listWords.end()), listWords.end());
    dequeNumbers.erase(std::unique(dequeNumbers.begin(), dequeNumbers.end()), dequeNumbers.end());

    std::map<int, std::string> map;
    std::transform(listWords.begin(), listWords.end(), dequeNumbers.begin(), 
                    std::inserter(map, map.end()), 
                    [](const auto& str, const int num) {
                        return std::make_pair(num, str);
                    });

    return map;
}
