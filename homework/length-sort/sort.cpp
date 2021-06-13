#include <forward_list>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& words) 
{
    words.sort();
    words.sort([](const std::string& lhs, const std::string& rhs) 
    {
        if (lhs.size() == rhs.size()) 
        {
            return lhs < rhs;
        }
        return lhs.size() < rhs.size();
    });
    std::deque<std::string> deq;
    std::move(words.begin(), words.end(), std::back_inserter(deq));
    return deq;
}