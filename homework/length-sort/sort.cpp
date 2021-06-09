#include <algorithm>
#include "sort.hpp"

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list)
{
    std::deque<std::string> res(list.begin(), list.end());

    std::sort(res.begin(), res.end(),
                [](const auto& lhs, const auto& rhs)
                { 
                    if ((lhs.size() == rhs.size()))
                    {
                        if (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }

                    return (lhs.size() < rhs.size() ? true : false);
                });
    
    return res;
}