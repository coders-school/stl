#include <algorithm>
#include "sort.hpp"

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list)
{
    std::deque<std::string> res(list.begin(), list.end());


    std::sort(res.begin(), res.end(), [](const auto& lhs, const auto& rhs)
                { return lhs.size() < rhs.size() ? true : false; });
    

    return res;
}