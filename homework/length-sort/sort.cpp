#include "sort.hpp"
#include <functional>

std::deque<std::string> lengthSort(const std::forward_list<std::string>& list_words)
{
    std::deque<std::string> deque{};
    for(const auto& str : list_words)
    {
        deque.push_back(str);
    }

    std::sort(deque.begin(), deque.end(), [](auto& str1, auto& str2)
    {return str1.size() < str2.size() || (str1 < str2 && str1.size() == str2.size()); });
    return deque;
}
