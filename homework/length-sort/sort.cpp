#include "sort.hpp"
#include <iterator>

std::deque<std::string> lengthSort(std::forward_list<std::string> s)
{
    std::deque<std::string> ret;

    s.sort(IsShorter());

    for(const auto & i :s)
    {
        ret.push_back(i);
    }

    return ret;
}