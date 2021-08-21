#pragma once
#include <string>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include "transformContainers.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> strList, std::deque<int> deq) {

    strList.sort();
    strList.erase(std::unique(strList.begin(), strList.end()), strList.end());

    std::sort(deq.begin(), deq.end());
    deq.erase(std::unique(deq.begin(), deq.end()), deq.end());

    std::map<int, std::string> newMap;
    std::transform(deq.begin(),deq.end(), strList.begin(), std::inserter(newMap, newMap.begin()),
                                                                        [] (const auto & number, const auto & str){
                                                                            return std::make_pair(number, str);
                                                                        });

    return newMap;
}
