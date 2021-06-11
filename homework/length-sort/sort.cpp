#include "sort.hpp"

#include <algorithm>

bool sort(const std::string& lhs, const std::string& rhs)
{
    if (lhs.size() == rhs.size())
        return lhs < rhs;
    return lhs.size() < rhs.size();
}

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list)
{
    std::deque<std::string> deq;

    for (const auto el : list)
    {
        deq.emplace_back(el);
    }

    std::sort(deq.begin(), deq.end(), sort);
    return deq;
}