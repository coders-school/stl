#include "sort.hpp"


std::deque<std::string> lengthSort(std::forward_list<std::string> &list)
{
    list.sort();

    std::multimap<unsigned, std::string> map_size_sort;
    for (auto &el : list){
        map_size_sort.insert(std::pair<unsigned, std::string>(el.size(), el));
    }

    std::deque<std::string> deq_temp;

    for (auto &el : map_size_sort)
    {
        deq_temp.push_back(el.second);
    }

    return deq_temp;
};