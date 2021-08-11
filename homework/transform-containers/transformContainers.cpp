#include "transformContainers.hpp"
std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deque){

list.sort();
list.erase((std::unique(begin(list), end(list))),end(list));
std::sort(deque.begin(), deque.end());
deque.erase((std::unique(begin(deque), end(deque))), end(deque));
std::map<int, std::string> map{};

if(list.size() == deque.size()){  
  std::transform(deque.begin(), deque.end(), 
               list.begin(), std::inserter(map, map.end()),
               [](const auto firstEl, const auto & secondEl){
                    return std::make_pair(firstEl, secondEl);
  });
}

return map;
};