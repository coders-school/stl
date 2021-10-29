#include <forward_list>
#include <iostream>
#include <algorithm>

#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>lista)
{
    std::deque<std::string> temp;
    lista.sort();

    for(auto a: lista)
    {
        temp.push_back(a);
    }

    std::sort(temp.begin(), temp.end(), [](std::string a, std::string b){return a.length()<b.length();});

    return temp;
}