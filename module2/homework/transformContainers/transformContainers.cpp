#include "transformContainers.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> myList, std::deque<int> myDeque) {
    std::map<int, std::string> myMap;
    std::sort(myDeque.begin(), myDeque.end());
    auto dequeIt = std::unique(myDeque.begin(), myDeque.end());
    myDeque.erase(dequeIt, myDeque.end());

    myList.sort();
    auto listIt = std::unique(myList.begin(), myList.end());
    myList.erase(listIt, myList.end());

    std::deque<std::string> myDequeOfString (myList.begin(), myList.end());

    for (auto it = 0; it < myDeque.size(); it++) {
        myMap.emplace(std::make_pair(myDeque.at(it), myDequeOfString.at(it)));
    }

    return myMap;
}
