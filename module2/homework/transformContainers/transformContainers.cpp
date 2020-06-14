#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int>deque){

std::sort(deque.begin(), deque.end());
deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

list.sort();
list.erase(std::unique(list.begin(), list.end()), list.end());

std::map<int, std::string> map;
std::transform(deque.begin(), deque.end(), list.begin(),std::inserter(map, map.end()),[](int el1, std::string el2){return std::pair(el1, el2);});

return map;
}
