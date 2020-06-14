#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <map>
#include <list>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int>deque){

std::sort(deque.begin(), deque.end());
deque.erase(std::unique(deque.begin(), deque.end()), deque.end());

list.sort();
list.erase(std::unique(list.begin(), list.end()), list.end());

std::map<int, std::string> map;
return map;
}
