#pragma once
#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <string>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& listStrings, std::deque<int>& deqInts) {
    listStrings.sort();
    listStrings.unique();
    std::sort(deqInts.begin(), deqInts.end());
    std::deque<int>tmp{};
    for(auto it = deqInts.begin(); it != deqInts.end(); ++it) {

        if(*it != *(it +1) ) {
            tmp.push_back(*it);
        }else {
           continue;
        }
    }
    std::map<int, std::string> returnedMap{};
    std::transform(begin(tmp), end(tmp), begin(listStrings) 
                    ,std::inserter(returnedMap, returnedMap.begin())
                    ,[](const auto& num, const auto& word) -> decltype(returnedMap)::value_type {
                        return {num, word};
                    });


    return returnedMap;
}   