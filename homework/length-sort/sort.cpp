#include "sort.hpp"

bool compareSize(const std::string &a, const std::string &b)
{
    if (a.size() == b.size())
    {
        return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    }
    return a.size() < b.size();
}

std::deque<std::string> lengthSort(std::forward_list<std::string> &inputList)
{
    std::deque<std::string> sortedList;
    for (auto &el : inputList)
    {
        sortedList.push_back(el);
    }
    std::sort(sortedList.begin(), sortedList.end(), compareSize);
    return sortedList;
}