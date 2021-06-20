#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> list){
    list.sort();
    std::deque<std::string> deque {};   
    for (auto listWord : list){
        deque.push_back(listWord);
    }
    std::sort(deque.begin(),deque.end(), [](const std::string& first, const std::string& second)
            {return first.size() < second.size();});
    return deque;
};

