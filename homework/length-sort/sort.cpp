#include "sort.hpp"
#include <deque>
#include <forward_list>
std::deque<std::string> lengthSort(std::forward_list<std::string> inputList)
{
    std::forward_list<std::string> listForSort = inputList;
    listForSort.sort();
    size_t howManyUsed = 0;
    std::deque<std::string> retSorted;
    int i = 1;
    size_t size = 0;
    for(auto it : listForSort){
        size++;
    }
    while(howManyUsed < size){
        for(auto it : listForSort){
            if(it.size() == i){ 
            retSorted.push_back(it);
            howManyUsed++;
            }
        }
        i++;
    }
    return retSorted;
}