#pragma once
#include <list>
#include <deque>
#include <string>
#include <map>
#include <algorithm>

std::map<int,std::string> zip(std::list<std::string> values, std::deque<int> keys)
{
    std::map<int,std::string> result; 
    auto keysIter = std::begin(keys);
    auto valuesIter = std::begin(values);

     //for ( ; keysIter != std::end(keys), valuesIter != std::end(values); keysIter++, valuesIter++ )
     //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!danger!
     for ( ; keysIter != std::end(keys); keysIter++, valuesIter++ )
     {
        result.insert(std::make_pair(*keysIter, *valuesIter));
     }
    return result; 
}

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& list, std::deque<int>& deque)
{
    std::unique(std::begin(deque), std::end(deque));
    std::unique(std::begin(list), std::end(list));
    return zip(list, deque) ; 
}
