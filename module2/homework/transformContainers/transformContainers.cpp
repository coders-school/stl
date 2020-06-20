#include "transformContainers.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> dataList,
                                                           std::deque<int> dataDeque) {
    dataList.sort();
    std::unique(dataList.begin(), dataList.end());

    std::sort(dataDeque.begin(), dataDeque.end());
    dataDeque.erase(std::unique(dataDeque.begin(), dataDeque.end()), dataDeque.end());

    std::map<int, std::string> result;

    std::transform(dataList.cbegin(), dataList.cend(), dataDeque.cbegin(), std::inserter(result, result.end()),
                   [](const auto& elemList, const auto& elemDeque) {
                       return std::make_pair(elemDeque, elemList);
                   });

    return result;
}
