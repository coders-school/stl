#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> list){
    std::deque<std::string> deque {};   
    for (auto listWord : list){
        deque.push_back(listWord);
    }
    return deque;
};
