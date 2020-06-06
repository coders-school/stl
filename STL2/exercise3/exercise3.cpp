#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <string>

std::map<int, std::string> removeDuplicateAndTranformToMap(
                            std::list<std::string> list, 
                            std::deque<int> deque) {
    list.sort();
    list.unique();
    std::sort(begin(deque), end(deque));
    deque.erase(std::unique(begin(deque), end(deque)), end(deque));
    
    std::map<int, std::string> map;
    std::transform(begin(deque), end(deque), begin(list),
      std::inserter(map, map.end()), 
      [](const int key, const std::string& value){
          return std::make_pair(key, value);
      });

    return map;
}
