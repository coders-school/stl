#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string> &sorted_list)
{

    sorted_list.sort([](std::string & x, std::string & y)
    {
        if (x.size() == y.size())
        {
            return x < y;
        }
        return x.size() < y.size();
    });
    
    std::deque<std::string> Deque_words(sorted_list.begin(), sorted_list.end());
    return Deque_words;
}