#include "sort.hpp"
#include <algorithm>
#include <functional>
#include <iostream>


auto proj = [](const std::string& s){ return std::make_tuple(s.size(), std::ref(s)); };

std::deque<std::string> lengthSort(std::forward_list<std::string> & list)
{
    list.sort([](const std::string& a, const std::string &b ) {
        if(a.size() == b.size())
        {
            return a < b;
        }
        else return a.size() < b.size();
    });

    return std::deque<std::string>(list.begin(), list.end());
}

