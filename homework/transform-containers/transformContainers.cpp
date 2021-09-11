#include <deque>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>


template<typename Container>
void print(Container container)
{
    for(const auto & elem: container)
        std::cout<<elem<<"  |  ";
    std::cout<<'\n';
}

void printMap(std::map<int,std::string> c)
{
    for(auto& elem: c)
    {
        std::cout<<'\"'<<elem.first<<'\"'<<" = "<<elem.second<<" ";
    }
    std::cout<<'\n';
}

void removeListDuplicates(std::list<std::string>& list)
{   
    list.sort();
    list.unique();
}

void removeDequeDuplicates(std::deque<int>& deque)
{   
    std::sort(deque.begin(),deque.end());
    auto last = std::unique(deque.begin(),deque.end());
    deque.erase(last, deque.end());
}


void generateMap(std::deque<int>& deque, std::list<std::string>& list, std::map<int,std::string>& map)
{
    size_t mapSize = std::min(deque.size(),list.size());
    std::transform(deque.begin(), 
                   deque.begin() + mapSize ,
                   list.begin(), 
                   std::inserter(map, map.end()),
                   [](auto key, auto value) { return std::make_pair(key, value); });
}

std::map<int,std::string>  removeDuplicateAndTranformToMap( std::list<std::string> list, std::deque<int> deque)
{
    std::map<int,std::string> map;
    removeListDuplicates(list);
    removeDequeDuplicates(deque);
    generateMap(deque,list,map);
    return map;
}
